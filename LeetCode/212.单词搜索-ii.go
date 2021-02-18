/*
 * @lc app=leetcode.cn id=212 lang=golang
 *
 * [212] 单词搜索 II
 */
/*
方法一: 遍历words, 搜索board
O(N * m * m * 4^k),  k = avg length of words

方法二: Trie
a. all words -> trie, build a prefix tree
b. for the board: DFS(expand 4 directions on every level)
*/

package LeetCode

// @lc code=start
var dx = []int{-1, 1, 0, 0} // 上，下，左，右；注意dx控制数组中dim 1, 即纵坐标
var dy = []int{0, 0, -1, 1}
var END_OF_WORD = '#'

func findWords(board [][]byte, words []string) []string {
	if len(board) < 1 || len(board[0]) < 1 || len(words) < 1 {
		return []string{}
	}

	result := []string{}
	wordsOccurred := map[string]bool{}
	m := len(board)
	n := len(board[0])

	// create a Trie
	trie := CreateTrie()
	for _, word := range words {
		trie.Insert(word)
	}

	var dfs func(i int, j int, curr_word string, curr_dict map[rune]interface{})
	dfs = func(i int, j int, curr_word string, curr_dict map[rune]interface{}) {
		new_word := curr_word + string(rune(board[i][j]))
		curr_dict = curr_dict[rune(board[i][j])].(map[rune]interface{})
		// fmt.Printf("Search word: %s \n", new_word)
		if c, ok := curr_dict[END_OF_WORD].(rune); ok && c == END_OF_WORD {
			wordsOccurred[new_word] = true
		}
		// temporarily delete current character
		tmpChar := byte(0)
		tmpChar, board[i][j] = board[i][j], '@'

		// expand to 4 directions
		for k := 0; k < 4; k++ {
			x := i + dx[k]
			y := j + dy[k]
			if 0 <= x && x < m && 0 <= y && y < n &&
				board[x][y] != '@' &&
				curr_dict[rune(board[x][y])] != nil {
				dfs(x, y, new_word, curr_dict)
			}
		}

		// recovery char
		board[i][j] = tmpChar
	}

	// DFS the board
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			char := rune(board[i][j])
			//fmt.Printf("origin dfs: %c\n", char)
			if trie.root[char] != nil { // pruning
				dfs(i, j, "", trie.root)
			}
		}
	}

	// collect all words
	for k := range wordsOccurred {
		result = append(result, k)
	}
	return result
}

/**
* COPIED FROM 208.
**/
type Trie struct {
	// map of string -> map[string]interface | nil
	root      map[rune]interface{}
	endOfWord rune
}

/** Initialize your data structure here. */
func CreateTrie() Trie {
	return Trie{
		root:      make(map[rune]interface{}),
		endOfWord: END_OF_WORD,
	}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	if len(word) < 1 {
		return
	}

	node := this.root
	for _, c := range word {
		if node[c] != nil {
			if nodeTemp, ok := node[c].(map[rune]interface{}); ok {
				node = nodeTemp
			} else {
				//fmt.Printf("unknown error: type assertion failed. node value: %+v \n", nodeTemp)
			}
		} else {
			node[c] = make(map[rune]interface{}, 1)
			node = node[c].(map[rune]interface{})
		}
	}
	node[this.endOfWord] = this.endOfWord
}

// @lc code=end
