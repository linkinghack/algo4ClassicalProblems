/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include<map>
#include<vector>
// #include<iostream>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> pool;
        vector<int> sol;
        for (size_t i = 0; i < nums.size(); i++)
        {
            pool.insert({nums[i], i});
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int hope = target - nums[i];
            map<int,int>::iterator phope = pool.find(hope);
            if (phope != pool.end() && phope->second != i) {
                sol.push_back(i);
                sol.push_back(phope->second);
                return sol;
            }
        }
        return sol;
    }
};

// int main(void) {
//     vector<int> nums = {2,7,11,15};
//     Solution s;
//     auto sol = s.twoSum(nums, 9);
//     cout<<sol[0]<<" "<<sol[1]<<endl;
//     return 0;
// }
// @lc code=end

