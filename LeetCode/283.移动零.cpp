/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int notZeroPosition = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) { // Condition.1
                nums[notZeroPosition] = nums[i];

                // i != notZeroPosition即发生了0和非0的位置调换
                if (i != notZeroPosition) {
                    nums[i] = 0;
                } 
                
                notZeroPosition++; // Condition.1 满足即确定了一个非0位置, 目标idx后移 
            }
        }
    }
};
// @lc code=end

