/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < 1)
        {
            return nums;
        }
        
        deque<int> window;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            // 窗口中元素超过k，弹出最老元素（滑动窗口）
            if(i >= k && window.front() <= i - k)
            {
                window.pop_front();
            }

            // 比较新进元素与窗口中所有元素，弹出所有小元素
            //  此处从back() 开始弹出,看起来是反向的,但是可以确保最前端大数和新进中数间夹的小数被弹出
            while (window.size() > 0 && nums[window.back()] <= nums[i]){
                window.pop_back();
            }

            // 新元素入窗口
            window.push_back(i);

            // 调整结束后, window中的最左端一定是最大值(不够大都已经弹出)
            if (i >= k-1) 
            {
                result.push_back(nums[window.front()]);
            }
        }
        
        return result;
    }
};
// @lc code=end

