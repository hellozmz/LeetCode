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
 * 
 */

// @lc code=start
class Solution {
public:
    /**
     * @brief 单调栈问题，找到下一个比当前值大的数字。
     * 相当于是单调栈的一个变种。
     * 单调栈需要最后将当前值压入栈中
     * 
     * @param height 
     * @return int 
     */
    int trap(vector<int>& height) {
        int len = height.size();
        if (len <= 2) {
            return 0;
        }
        int result = 0;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < len; ++i) {
            if (height[i] < height[st.top()]) {
                st.push(i);
            } else if (height[i] == height[st.top()]) {
                st.pop();
                st.push(i);
            } else {
                while (!st.empty() && height[st.top()] < height[i]) {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty()) {
                        int minHeight = min(height[st.top()], height[i]);
                        result += (i - st.top() - 1) * (minHeight - height[mid]);
                    }
                }
                st.push(i);
            }
        }

        return result;
    }
};
// @lc code=end

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         if (height.size() <= 2) return 0; // 可以不加
//         stack<int> st; // 存着下标，计算的时候用下标对应的柱子高度
//         st.push(0);
//         int sum = 0;
//         for (int i = 1; i < height.size(); i++) {
//             if (height[i] < height[st.top()]) {     // 情况一
//                 st.push(i);
//             } if (height[i] == height[st.top()]) {  // 情况二
//                 st.pop(); // 其实这一句可以不加，效果是一样的，但处理相同的情况的思路却变了。
//                 st.push(i);
//             } else {                                // 情况三
//                 while (!st.empty() && height[i] > height[st.top()]) { // 注意这里是while
//                     int mid = st.top();
//                     st.pop();
//                     if (!st.empty()) {
//                         int h = min(height[st.top()], height[i]) - height[mid];
//                         int w = i - st.top() - 1; // 注意减一，只求中间宽度
//                         sum += h * w;
//                     }
//                 }
//                 st.push(i);
//             }
//         }
//         return sum;
//     }
// };
