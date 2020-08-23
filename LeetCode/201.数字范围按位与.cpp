/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 * 
 * 连续数字按位与，特点是具有公共前缀。
 * 某一个bit之后都不同，则按全部按位与一定得0
 *     00001 10000
 *     00001 10010
 *     00001 11010
 * ...
 * 
 * 找出目标区间中首尾位置得公共前缀即可
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bits = 0;
        while(m != n) {
            m >>= 1; // 首尾数字同步左移，直到相等
            n >>= 1;
            bits ++; // 记录移动位数，用户最后恢复数字
        }
        return m << bits;  // 恢复最初位置
    }
};
// @lc code=end

