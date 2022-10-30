/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (43.57%)
 * Likes:    1732
 * Dislikes: 0
 * Total Accepted:    208.6K
 * Total Submissions: 478.4K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入： heights = [2,4]
 * 输出： 4
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> left(len), right(len);        // 左右边界都是不包含的
        stack<int> st;

        for (int i=0; i < len; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            left[i] = (st.empty() ? -1: st.top());
            st.push(i);
        }

        stack<int> st1;
        st.swap(st1);
        for (int i = len -1; i >= 0; --i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            right[i] = (st.empty()? len : st.top());
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < len; ++i) {
            maxArea = max(maxArea, (right[i] - left[i] - 1) * heights[i]);
        }

        return maxArea;
    }
};
// @lc code=end

