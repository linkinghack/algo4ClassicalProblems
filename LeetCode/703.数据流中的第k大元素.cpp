/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第K大元素
 */

// @lc code=start
#include<queue>
#include<vector>
#include<functional>
// #include<iostream>

using namespace std;

class KthLargest {
public:
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (size_t i = 0; i < nums.size(); i++)
        {
            add(nums[i]);
        }
    }
    
    int add(int val) {
        if (pq.size() < k)
        {
            pq.push(val);
            return pq.top();
        } else {
            int top = pq.top();
            if(top >= val) {
                return top;
            } else {
                pq.push(val);
                pq.pop();
                return pq.top();
            }
        }
    }
};

// int main(void) {
//     vector<int> nums = {4,5,8,2};
//     KthLargest kt(3, nums);
//     cout<<kt.add(3)<<" ";
//     cout<<kt.add(5)<<" ";
//     cout<<kt.add(10)<<" ";
//     cout<<kt.add(9)<<" ";
//     cout<<kt.add(4)<<" ";
//     return 0;
// }

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

