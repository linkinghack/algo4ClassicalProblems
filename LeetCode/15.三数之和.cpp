/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return sortFind(nums);
    }


    // O(n^2)
    vector<vector<int>> sortFind(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<int> sumRecord;
        for(int i = 0; i < nums.size()-2; i++) {
            // 跳过连续的相同数字(刚处理完结果一样，一方面节省失败验证的时间，一方面避免重复结果)
            // 依赖前一步排序
            if(i >= 1 && nums[i] == nums[i-1]) {
                continue;
            }

            // 内层循环 寻找第二个数并处记录两数和
            for(int j = i+1; j < nums.size(); j++) {
                if(sumRecord.find(-nums[j]-nums[i])==sumRecord.end()) {
                    sumRecord.insert(-nums[i]-nums[j]);
                } else {
                    res.push_back(vector<int> {-nums[i] - nums[j], nums[i], nums[j]});
                }
            }
        }
        return res;
    }
};

int main(void) {
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>> res = s.threeSum(nums);
    return 0;
}
// @lc code=end

