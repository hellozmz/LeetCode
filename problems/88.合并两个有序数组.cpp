/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (48.76%)
 * Likes:    671
 * Dislikes: 0
 * Total Accepted:    223.9K
 * Total Submissions: 458.5K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出：[1,2,2,3,5,6]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -10^9 
 * nums1.length == m + n
 * nums2.length == n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // 题目中指定了nums1中的长度大于等于 m + n，那么就不再考虑这个问题了
        int index1 = m - 1;
        int index2 = n - 1;
        int cur = m + n -1;
        while (index1 < cur) {
            if (index1 >= 0 && nums1[index1] > nums2[index2]) {
                nums1[cur--] = nums1[index1--];
            } else {
                nums1[cur--] = nums2[index2--];
                if(index2 < 0) {
                    break;
                }
            }
        }
        return;
    }
};
// @lc code=end

