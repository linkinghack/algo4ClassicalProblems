/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 */

// @lc code=start

#include<string.h>
bool isAnagram(char * s, char * t){
    char alphas[26] = {0};
    // resolve s
    for(int i = 0; i < strlen(s); i++) {
        alphas[s[i] - 'a'] += 1;
    }

    // resolve t
    for(int i = 0; i < strlen(t); i++) {
        alphas[t[i] - 'a'] -= 1;
    }

    for(int i = 0; i < 26; i++) {
        if (alphas[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}


// @lc code=end

