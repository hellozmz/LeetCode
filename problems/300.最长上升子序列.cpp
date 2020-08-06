/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (43.69%)
 * Likes:    405
 * Dislikes: 0
 * Total Accepted:    44.9K
 * Total Submissions: 102.8K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 * 
 * 示例:
 * 
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 
 * 说明:
 * 
 * 
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n^2) 。
 * 
 * 
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS0(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return 1;
        }
        int max = 1;
        int tmp_max = 0;
        std::vector<int> dp(len, 1);
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    tmp_max = std::max(tmp_max, dp[j]);
                }
            }
            dp[i] = tmp_max + 1;
            max = std::max(max, dp[i]);
            tmp_max = 0;
        }
        return max;
    }

    int lengthOfLIS1(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }
        std::vector<int> list(len + 1);     // 长度要加上1，为了后边做准备
        int count = 1;
        list[count] = nums[0];
        for (int i = 0; i < len; ++i) {
            if (nums[i] > list[count]) {
                list[++count] = nums[i];
            } else {
                int l = 0;
                int r = count;
                int pos = 0;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (list[mid] < nums[i]) {
                        l = mid + 1;
                        pos = mid;
                    } else {
                        r = mid;
                    }
                }
                list[pos + 1] = nums[i];
            }
        }
        return count;
    }

    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int count = 1;
        std::vector<int> list(len + 1);

        if (len < 2) {
            return len;
        }

        list[count] = nums[0];
        for (int i = 0; i < len; ++i) {
            if (nums[i] > list[count]) {
                list[++count] = nums[i];
                // std::cout << "count=" << count << ", value=" << list[count] << std::endl;
            } else {
                int left = 1;
                int right = count;
                int target_pos = left;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (nums[i] > list[mid]) {
                        left = mid + 1;
                        target_pos = left;
                    } else {
                        right = mid;
                    }
                }
                list[target_pos] = nums[i];
            }
        }

        // for (int i = 1; i <= count; ++i) {
        //     std::cout << list[i] << " ";
        // }
        // std::cout << std::endl;
        return count;
    }
};
// @lc code=end

