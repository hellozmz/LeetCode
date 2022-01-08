/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (43.50%)
 * Likes:    1688
 * Dislikes: 0
 * Total Accepted:    203.3K
 * Total Submissions: 467.4K
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
        if (len == 0) {
            return 0;
        }
        std::stack<int> stack;      // 栈中记录的元素都比当前值高，这样才能保证当前节点的高度是最低的，才能让计算面积的时候可以使用当前的节点高度
        std::vector<int> left(len), right(len);         // 记录当前节点左右中，可以比这个高度高的索引
        for (int i = 0; i < len; ++i) {
            while (!stack.empty() && heights[stack.top()] >= heights[i]) {          // 栈中记录的元素都比当前值高
                stack.pop();
            }
            left[i] = (stack.empty() ? -1 : stack.top());
            stack.push(i);
        }
        std::stack<int> tmp;
        stack.swap(tmp);
        for (int i = len - 1; i >= 0; --i) {
            while (!stack.empty() && heights[stack.top()] >= heights[i]) {
                stack.pop();
            }
            right[i] = (stack.empty() ? len : stack.top());
            stack.push(i);
        }

        int result = 0;
        for (int i = 0; i < len; ++i) {
            result = std::max(heights[i] * (right[i] - left[i] -
             1), result);
        }
        return result;
        
    }
};
// @lc code=end

/**
 * @brief 
 * class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        
        stack<int> mono_stack;
        for (int i = 0; i < n; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
            mono_stack.push(i);
        }

        mono_stack = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
                mono_stack.pop();
            }
            right[i] = (mono_stack.empty() ? n : mono_stack.top());
            mono_stack.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
