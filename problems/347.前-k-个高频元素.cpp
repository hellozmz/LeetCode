/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (59.83%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    33.7K
 * Total Submissions: 56.3K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 说明：
 * 
 * 
 * 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
 * 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = nums.size();
        // 统计各个元素出现个数
        std::unordered_map<int, int> hashtable;   // 元素，频次
        for (int i = 0; i < len; ++i) {
            ++hashtable[nums[i]];
        }

        // todo 为什么要写成这个样子才能通过编译
        auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.second > b.second;
            };
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            decltype(cmp)> topk(cmp);
        for (auto iter = hashtable.begin(); iter != hashtable.end(); ++iter) {
            if (topk.size() < k) {
                topk.push(std::make_pair(iter->first, iter->second));
            } else if (iter->second > topk.top().second) {
                topk.pop();
                topk.push(std::make_pair(iter->first, iter->second));
            } else {
                // 不需要处理
            }
        }

        std::vector<int> result;
        while(!topk.empty()) {
            result.push_back(topk.top().first);
            topk.pop();
        }
        return result;
    }
};
// @lc code=end

