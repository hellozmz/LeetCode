/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (59.35%)
 * Likes:    3062
 * Dislikes: 0
 * Total Accepted:    387.2K
 * Total Submissions: 651.7K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * 
 * class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};

 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        std::stack<int> stk;        // 记录单调高度的索引，记录的是单调递减
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int top = stk.top();
                stk.pop();
                // 如果左边没有元素了，跳出循环，不需要进行栈的处理，相当于是左边没有可以构成“坑”的位置接雨水
                if (stk.empty()) {
                    break;
                }
                int left_index = stk.top();
                int h = (std::min(height[i], height[left_index]) - height[top]);
                int w = (i - left_index - 1);
                ans += w * h;
            }
            stk.push(i);
            // std::cout << "i = " << i << ", ans = " << ans << std::endl;
        }
        return ans;
    }
};
// @lc code=end

