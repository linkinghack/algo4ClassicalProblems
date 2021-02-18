/*
 * @lc app=leetcode.cn id=208 lang=golang
 *
 * [208] 实现 Trie (前缀树)
 */

package LeetCode

// @lc code=start
type Trie struct {
	// map of string -> map[string]interface | nil
	root      map[rune]interface{}
	endOfWord rune
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{
		root:      make(map[rune]interface{}),
		endOfWord: '#',
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

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	if len(word) < 1 {
		return false
	}

	node := this.root
	for _, c := range word {
		if node[c] != nil {
			node = node[c].(map[rune]interface{})
		} else {
			return false
		}
	}

	if node[this.endOfWord] == this.endOfWord {
		return true
	} else {
		return false
	}
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	if len(prefix) < 1 {
		return false
	}

	node := this.root
	for _, c := range prefix {
		if node[c] != nil {
			node = node[c].(map[rune]interface{})
		} else {
			return false
		}
	}

	return true
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
// @lc code=end
