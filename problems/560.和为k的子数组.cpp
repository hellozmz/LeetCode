/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 *
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.16%)
 * Likes:    199
 * Dislikes: 0
 * Total Accepted:    14.1K
 * Total Submissions: 32.7K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 * 
 * 示例 1 :
 * 
 * 
 * 输入:nums = [1,1,1], k = 2
 * 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
 * 
 * 
 * 说明 :
 * 
 * 
 * 数组的长度为 [1, 20,000]。
 * 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        map[0] = 1;
        int count = 0;
        int size = nums.size();
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
            if (map.count(sum - k) > 0) {
                count += map[sum-k];
            }
            ++map[sum];
        }
        return count;
    }
};
// @lc code=end


// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         mp[0] = 1;
//         int count = 0, pre = 0;
//         for (auto& x:nums) {
//             pre += x;
//             if (mp.find(pre - k) != mp.end()) {
//                 count += mp[pre - k];
//             }
//             mp[pre]++;
//         }
//         return count;
//     }
// };
