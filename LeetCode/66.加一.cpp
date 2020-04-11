/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n-1; i >= 0; i--) {
            if(digits[i] == 9)
            {
                // 处理进位
                digits[i] = 0;
            } else
            {
                // 进位结束或不需要进位
                digits[i]++;
                return digits;
            }
        }
        
        // 99999 的情况，n位遍历结束全需要进位
        // 100000
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
// @lc code=end

