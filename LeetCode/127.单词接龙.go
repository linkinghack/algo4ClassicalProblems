/*
 * @lc app=leetcode.cn id=127 lang=golang
 *
 * [127] 单词接龙
 */
package LeetCode

// @lc code=start
import "container/list"

func ladderLength(beginWord string, endWord string, wordList []string) int {
	type BfsElem struct {
		word  string
		level int
	}

	wordPatternMap := map[string][]string{}
	L := len(beginWord)

	// 构建字典匹配表
	for _, word := range wordList {
		for i := 0; i < L; i++ {
			// hit -> h*t, *ht, hi*
			pattern := word[:i] + "*" + word[i+1:]
			wordPatternMap[pattern] = append(wordPatternMap[pattern], word)
		}
	}

	// BFS
	queue := list.New()
	queue.PushBack(&BfsElem{beginWord, 1})
	visited := map[string]bool{}
	for queue.Len() > 0 {
		currentWordElem := queue.Front()
		queue.Remove(currentWordElem)
		currentWord := currentWordElem.Value.(*BfsElem)

		// 搜索过程即对每个word的每种pattern搜索，查看是否存在目标word
		for i := 0; i < len(currentWord.word); i++ {
			pattern := currentWord.word[:i] + "*" + currentWord.word[i+1:]
			for _, word := range wordPatternMap[pattern] {
				if word == endWord {
					return currentWord.level + 1
				}

				if !visited[word] {
					visited[word] = true
					queue.PushBack(&BfsElem{word: word, level: currentWord.level + 1})
				}
			}
		}
	}
	return 0
}

// @lc code=end
