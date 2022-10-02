/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (62.51%)
 * Likes:    1016
 * Dislikes: 0
 * Total Accepted:    241.5K
 * Total Submissions: 386.4K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 * 
 * 
 * 
 * 
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent0(vector<int>& nums, int k) {
        std::vector<int> result;
        if (nums.empty() || k == 0) {
            return result;
        }
        std::unordered_map<int, int> counts;
        for (auto i : nums) {
            ++counts[i];
        }
        // 典型的小顶堆
        auto cmp = [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
            return a.second > b.second;
        };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> min_heap(cmp);
        for (auto item : counts) {
            min_heap.push(std::make_pair(item.first, item.second));
            if (min_heap.size() > k) {
                // std::cout << "top value " << min_heap.top().first << ", " << min_heap.top().second << std::endl;
                min_heap.pop();
            }
        }
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().first);
            min_heap.pop();
        }
        return result;
    }


    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int i = 0; i < nums.size(); ++i) {
            ++counts[nums[i]];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        // greater a.value > b.value。最终的堆是从数组后面向前看的，也就是小顶堆
        // less a.value < b.value。默认值就是less，也就是左边的值小于右边的值，就是大顶堆
        for (auto& item : counts) {
            q.push({item.second, item.first});
            // cout << item.second << " " << item.first << endl;
            if (q.size() > k) {
                q.pop();
            }
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }
};
// @lc code=end

