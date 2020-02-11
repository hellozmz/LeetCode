/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 * 1.暴力法思路简单，但是要注意边界情况
 * 2.贪心法需要注意数据加进来的条件，就是历史数据的和要有正向激励，即大于0
 * 3.动态规划，和贪心法比较接近，但是开辟了一个新的数组
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int len = nums.size();
        int dp[len];
        for (int i=0; i<len; ++i) {
            if (i==0) {
                dp[i] = nums[i];
            } else {
                dp[i] = std::max(dp[i-1]+nums[i], nums[i]);
                max_sum = std::max(dp[i], max_sum);
            }
        }
        return max_sum;
    }

    // 贪心算法
    int maxSubArray_2(vector<int>& nums) {
        int max_sum = nums[0];
        int tmp_sum = 0;    // 记录（有正向激励的）历史数据的和
        int len = nums.size();
        for (int i=0; i<len; ++i) {
            if (tmp_sum > 0) {
                tmp_sum += nums[i];
            } else {
                tmp_sum = nums[i];
            }

            if (max_sum < tmp_sum) {
                max_sum = tmp_sum;
            }
        }

        return max_sum;
    }

    // 暴力
    int maxSubArray_1(vector<int>& nums) {
        int len = nums.size();
        int max_sum = nums[0];
        int tmp_sum = max_sum;
        for (int i=0; i<len; ++i) {
            tmp_sum = nums[i];
            if (tmp_sum >= max_sum) {
                max_sum = tmp_sum;
            }
            for (int j=i+1; j<len; ++j) {
                tmp_sum += nums[j];
                if (tmp_sum >= max_sum) {
                    max_sum = tmp_sum;
                }
            }
        }
        return max_sum;
    }
};
// @lc code=end

