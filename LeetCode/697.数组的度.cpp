/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
#include <vector>
#include <map>
#include<algorithm>

using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        map<int, int> counts;
        int currentMaxCount = 0, currentMaxCountNum = nums[0];
        for (size_t i = 0; i < n; i++)
        {
            counts[nums[i]]++;
            if (currentMaxCount < counts[nums[i]]) {
                currentMaxCount = counts[nums[i]];
                currentMaxCountNum = nums[i];
            }
        }
        return currentMaxCount;
    }
};
// @lc code=end

