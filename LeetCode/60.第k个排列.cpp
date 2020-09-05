/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // 每确定一位数，剩余数位的排列情况就只剩下 (n-i)! 种， i 为已确定的数位个数
        // 1. 准备 1~n 的阶乘，供计算情况数使用
        int factorials[n+1];
        factorials[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorials[i] = factorials[i-1] * i;
        }

        // 2. 中间变量准备
        string result = "";
        list<int> digits;  // 双向链表保存所有数位, 模拟无放回
        for (int i = 1; i <= n; i++) {
            digits.push_back(i); // i -> [1, 9]
        }

        // 3. 一位一位确定数字
        k--; // 下表从0开始的第k个排列情况。
        for (int i = n; i > 0; i--) {
            // i 为剩余待确定位数
            int idx = k / factorials[i-1]; // 向下取整。跳到全部排列的第(n-i)!个, 确定1位数字
            int targetDigit = listAt(&digits, idx);
            result.append(std::to_string(targetDigit));
            digits.remove(targetDigit);
            k -= idx * factorials[i-1];
        }

        return result;
    }

    int listAt(list<int> *list, int idx) {
        std::list<int>::iterator it = (*list).begin();
        while (it != (*list).end() && idx > 0)
        {
            it++;
            idx--;
        }
        
        return *it;
    }

};
// @lc code=end

