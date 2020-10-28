/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode-cn.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (43.48%)
 * Likes:    216
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 59.9K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回滑动窗口中的最大值。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 * 输出: [3,3,5,5,6,7] 
 * 解释: 
 * 
 * ⁠ 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 
 * 提示：
 * 
 * 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
 * 
 * 
 * 
 * 进阶：
 * 
 * 你能在线性时间复杂度内解决此题吗？
 * 
 */

/*
思路：使用一个两端开口的队列来保存有可能是滑动窗口最大值的数字的下标，队头永远存放当前滑动窗口最大值的下标。
在存入一个数字的下标之前，首先要判断队列里已有数字是否小于待存入的数字，
如果是，那么这些数字已经不可能成为滑动窗口的最大值，因此将它们依次从队尾删除。同时如果队头数字已经从窗口里滑动出去，那么它也要从队头删除
*/


// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        std::vector<int> result;
        std::deque<int> deque;
        // 初始化deque
        for (int i = 0; i < k; ++i) {
            while (!deque.empty() && nums[i] >= nums[deque.back()]) {
                deque.pop_back();
            }
            deque.push_back(i);
        }

        for (int i = k; i < size; ++i) {
            result.push_back(nums[deque.front()]);
            // for (auto&& a : deque) {
            //     cout << a << " ";
            // }
            // cout << endl;
            while (!deque.empty() && nums[i] >= nums[deque.back()]) {
                deque.pop_back();
            }
            // cout << "i = " << i << ", k = " << k  << ", i-k = " << i - k << ", front = " << deque.front() << endl;
            if (!deque.empty() && (deque.front() <= (i - k))) {
                // cout << "pop" << deque.front() << endl;
                deque.pop_front();
            }
            deque.push_back(i);
        }
        result.push_back(nums[deque.front()]);

        return result;
    }
};
// @lc code=end
