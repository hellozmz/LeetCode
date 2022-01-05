/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (60.80%)
 * Likes:    1076
 * Dislikes: 0
 * Total Accepted:    130K
 * Total Submissions: 213.8K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 * 
 * 
 * 
 * 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [1,8,6,2,5,4,8,3,7]
 * 输出: 49
 * 
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            // int h = std::min(height[left], height[right]);
            // maxarea = std::max(maxarea, h * (right - left));
            if (height[left] > height[right]) {
                maxarea = std::max(maxarea, height[right] * (right - left));
                --right;
            } else {
                maxarea = std::max(maxarea, height[left] * (right - left));
                ++left;
            }
        }
        return maxarea;
    }
    // int maxArea_old(vector<int>& height) {
    //     int len = height.size();
    //     int left = 0, right = len - 1;
    //     int area = 0;
    //     while (left < right) {
    //         area = std::max(area,
    //                         std::min(height[left], height[right]) *
    //                         (right - left));
    //         if (height[left] < height[right]) {
    //             ++left;
    //         } else {
    //             --right;
    //         }
    //     }
    //     return area;
    // }
};
// @lc code=end

