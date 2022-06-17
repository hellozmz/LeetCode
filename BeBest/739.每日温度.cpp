/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (68.35%)
 * Likes:    985
 * Dislikes: 0
 * Total Accepted:    238.1K
 * Total Submissions: 348.2K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 请根据每日 气温 列表 temperatures ，请计算在每一天需要等几天才会有更高的温度。如果气温在这之后都不会升高，请在该位置用 0 来代替。
 * 
 * 示例 1:
 * 
 * 
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 * 
 * i q
 * 0 73
 * 1 74             1
 * 2 75             1
 * 3 71 75          []
 * 4 69 71 75       []
 * 5 72 75          []
 * 6 76
 * 7 73
 * 
 * [89,62,70,58,47,47,46,76,100,70]
 *   0, 1, 2, 3, 4, 5, 6, 7,  8, 9
 *   8, 1, 5, 4, 3, 
 * 
 * 示例 2:
 * 
 * 
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 30 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 还是一个单调队列的问题
        std::deque<int> dq;
        int len = temperatures.size();
        std::vector<int> result(len, 0);
        for (int i = 0; i < len; ++i) {
            while (!dq.empty() && temperatures[dq.back()] < temperatures[i]) {
                result[dq.back()] = (i - dq.back());
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return result;
    }
};
// @lc code=end

