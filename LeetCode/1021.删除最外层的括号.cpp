/*
 * @lc app=leetcode.cn id=1021 lang=cpp
 *
 * [1021] 删除最外层的括号
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> bracketsStack;
        string result = "";
        string primitive = "";
        for (int i = 0; i < S.length(); i++) {
            if (S.at(i) == '(') {
                bracketsStack.push(S.at(i));
                primitive.push_back(S.at(i));
            } else {
                primitive.push_back(S.at(i));
                bracketsStack.pop();

                if (bracketsStack.size() == 0) {
                    // 一个原语子串已出现
                    result.append(primitive.substr(1, primitive.size() - 2));
                    primitive = "";
                }
            }
        }

        return result;
    }
};
// @lc code=end

