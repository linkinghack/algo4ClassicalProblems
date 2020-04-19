/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
// #include<stack>
// #include<map>
// #include<string>
// #include<iostream>
// using namespace std;
class Solution {
public:
    bool isValid(string s) {
        string char_stack = "";
        int idx = 0;
        map<char,char> parentheses;
        parentheses.insert(pair<char,char>(')', '('));
        parentheses.insert(pair<char,char>('}', '{'));
        parentheses.insert(pair<char,char>(']', '['));

        while (idx < s.size ())
        {
            char curr_c = s.at(idx);
            if (curr_c == '{' || curr_c == '(' || curr_c == '[')
            {
                char_stack.push_back(curr_c);
                continue;
            }
            if (curr_c == '}' || curr_c == ']' || curr_c == ')')
            {
                if (char_stack.size() < 1)
                {
                    return false;
                }
                
                char top = char_stack.back();
                char_stack.pop_back();
                if(top != parentheses.find(curr_c)->second ) {
                    return false;
                } 
            }
            idx++;
        }
        if (char_stack.size() > 0)
        {
            return false;
        }
        
        return true;
    }
};

// int main(void) {
//     Solution s;
//     s.isValid("()");
//     string stack = "";
//     stack.push_back('s');
//     cout<<stack<<endl;
// }
// @lc code=end

