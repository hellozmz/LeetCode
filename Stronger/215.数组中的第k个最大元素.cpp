/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.75%)
 * Likes:    1718
 * Dislikes: 0
 * Total Accepted:    662.1K
 * Total Submissions: 1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 
 * 
 * 提示： 
 * 
 * 
 * 1 
 * -10^4 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue，小顶堆
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        for (auto i : nums) {
            if (min_heap.size() < k) {
                min_heap.push(i);
            } else {
                if (min_heap.top() < i) {
                    min_heap.pop();
                    min_heap.push(i);
                }
            }
        }
        return min_heap.top();
    }
};

// 更加简单的方法
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int, vector<int>, greater<int>> pq;
//         for (int num : nums) {
//             pq.push(num);
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }
//         return pq.top();
//     }
// };
// @lc code=end

