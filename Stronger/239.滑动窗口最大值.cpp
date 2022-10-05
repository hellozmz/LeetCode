/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode.cn/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (50.03%)
 * Likes:    1893
 * Dislikes: 0
 * Total Accepted:    362.9K
 * Total Submissions: 725.4K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回 滑动窗口中的最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1], k = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
/**
 * @brief 暴力
 * 
 * @param nums 
 * @param k 
 * @return vector<int> 
 */
    vector<int> maxSlidingWindow0(vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i <= nums.size() - k; ++i) {
            int max = nums[i];
            for (int j = 0; j < k; ++j) {
                max = std::max(max, nums[i + j]);
            }
            result.push_back(max);
        }
        return result;
    }


/**
 * @brief 优先队列，自己做的并不好，看了好多眼答案
 * 
 * @param nums 
 * @param k 
 * @return vector<int> 
 */
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.push({nums[i], i});
        }
        result.push_back(q.top().first);
        for (int i = k; i < nums.size(); ++i) {
            q.push({nums[i], i});
            while (q.top().second + k - 1 < i) {
                q.pop();
            }
            result.push_back(q.top().first);
        }
        return result;
    }

/**
 * @brief 单调队列解决问题
 * 
 * @param nums 
 * @param k 
 * @return vector<int> 
 */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;   // 记录下标
        int len = nums.size();
        vector<int> result;
        for (int i = 0; i < len; ++i) {
            // 如果单调队列中有数据，则判断是否需要删除
            while (!q.empty() && i - q.front() >= k) {
                q.pop_front();
            }
            // 如果当前数值满足更新条件，则进行更新掉队列中的数据
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            // 插入需要的数据
            q.push_back(i);
            // 更新结果
            if (i + 1 >= k) {
                result.push_back(nums[q.front()]);
            }
        }
        return result;
    }
};
// @lc code=end

