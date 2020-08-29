/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
// #include <string>
// using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int nmap[10] = { 0 }; // 保存出现过的错误数字(10 digits)
        int A = 0, B = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                A++;
            } else {
                // nmap中使用正数表示猜错但存在的数
                // 负值表示猜错数
                if ( nmap[charToInt(guess[i])]-- > 0) {
                    B++;
                }
                if ( nmap[charToInt(secret[i])]++ < 0 ) {
                    B++;
                }

            }
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }

    char intToChar(int n) {
        return '0' + n;
    }
    int charToInt(char c) {
        return c - '0';
    }
};
// @lc code=end
