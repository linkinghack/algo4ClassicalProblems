/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
       // F(n) = F(n-1) + F(n-2)
       // F(1) = 1;  F(2) = 2

       // 初始化为0可以更好的处理n = 1, n = 2的情况
       int a = 0, b = 0;
       int result = 1;
       for (int i = 1; i <= n; i++ ) {
           a = b;
           b = result;
           result = a + b;
       }

       return result;
    }
};
// @lc code=end

