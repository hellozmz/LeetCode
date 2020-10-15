/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (40.00%)
 * Likes:    270
 * Dislikes: 0
 * Total Accepted:    48.9K
 * Total Submissions: 122.2K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<std::vector<int>> merged;
        std::sort(intervals.begin(), intervals.end(),
                  [](std::vector<int>& a, std::vector<int>& b) {
                      return a[0] < b[0];
        });

        for (auto& couple : intervals) {
            auto left = couple[0];
            auto right = couple[1];
            if (merged.size() == 0 || merged.back()[1] < left) {
                merged.push_back({left, right});
                // merged.emplace_back<std::vector<int>>({left, right});
                // std::cout << merged.size() << std::endl;
            } else {
                merged.back()[1] = std::max(merged.back()[1], right);
            }
        }
        return merged;
    }
};
// @lc code=end

