/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */
#include<vector>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> merge;
        vector<int>::iterator iter1 = nums1.begin();
        vector<int>::iterator iter2 = nums2.begin();
        while (iter1 != nums1.end() || iter2 != nums2.end())
        {
            if (iter1 != nums1.end() && *iter1 <= *iter2)
            {
                // cout<< "Iter1: "<< *iter1<<endl;
                merge.push_back(*iter1);
                ++iter1;
            } else {
                // cout<< "Iter2: "<< *iter2<<endl;
                merge.push_back(*iter2);
                ++iter2;
            }
        }
        int len = nums1.size() + nums2.size();
        if (len % 2 != 0) {
            return double(merge[len / 2]);
        } else {
            return (merge[len / 2] + merge[(len/2)-1]) / 2.0;
        }
        
    }
};

// int main(){
//     vector<int> nums1 = {1,2};
//     vector<int> nums2 = {3,4};
//     Solution s;
//     double solu = s.findMedianSortedArrays(nums1, nums2);
//     cout<<solu<<endl;
// }
// @lc code=end

