/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (48.19%)
 * Likes:    817
 * Dislikes: 0
 * Total Accepted:    49.4K
 * Total Submissions: 102.5K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> left_max(size, 0), right_max(size, 0);
        if (size <= 1) {
            return 0;
        }
        left_max[0] = height[0];
        right_max[size-1] = height[size-1];
        for (int i = 1; i < size; ++i) {
            left_max[i] = std::max(height[i], left_max[i-1]);
            // cout << left_max[i] << " ";
        }
        // cout << endl;
        for (int i = size-2; i >= 0; --i) {
            right_max[i] = std::max(height[i], right_max[i+1]);
            // cout << right_max[i] << " ";
        }
        // cout << endl;

        int result = 0;
        for (int i = 0 ; i < size; ++i) {
            result += (std::min(left_max[i], right_max[i]) - height[i]);
        }
        return result;
    }
};
// @lc code=end

