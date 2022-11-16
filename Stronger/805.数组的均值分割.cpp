/*
 * @lc app=leetcode.cn id=805 lang=cpp
 *
 * [805] 数组的均值分割
 *
 * https://leetcode.cn/problems/split-array-with-same-average/description/
 *
 * algorithms
 * Hard (30.02%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 18.9K
 * Testcase Example:  '[1,2,3,4,5,6,7,8]'
 *
 * 给定你一个整数数组 nums
 * 
 * 我们要将 nums 数组中的每个元素移动到 A 数组 或者 B 数组中，使得 A 数组和 B 数组不为空，并且 average(A) ==
 * average(B) 。
 * 
 * 如果可以完成则返回true ， 否则返回 false  。
 * 
 * 注意：对于数组 arr ,  average(arr) 是 arr 的所有元素除以 arr 长度的和。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,3,4,5,6,7,8]
 * 输出: true
 * 解释: 我们可以将数组分割为 [1,4,5,8] 和 [2,3,6,7], 他们的平均值都是4.5。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [3,1]
 * 输出: false
 * 
 * 
 * [6,8,18,3,1]
 * 
 * 提示:
 * 
 * 
 * 1 <= nums.length <= 30
 * 0 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool splitArraySameAverage0(vector<int>& nums) {
        int len = nums.size();
        long sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) {
            return false;
        }
        long mid = sum / 2;
        vector<vector<bool>> dp(len + 1, vector<bool>(mid + 1, false));
        // init
        dp[0][0] = true;
        // dp
        for (int i = 1; i <= len; ++i) {
            int num = nums[i- 1];
            for (int j = mid; j >= 0; --j) {
                dp[i][j] = dp[i-1][j];
                if (j - num >= 0) {
                    dp[i][j] = dp[i - 1][j - num] || dp[i][j];
                }
            }
        }

        for (auto& v : dp) {
            for (auto i : v) {
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;

        return dp[len][mid];
    }


    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), m = n / 2;
        // 求和
        int sum = accumulate(nums.begin(), nums.end(), 0);
        bool isPossible = false;
        // 剪枝
        for (int i = 1; i <= m; i++) {
            if (sum * i % n == 0) {
                isPossible = true;
                break;
            }
        }  
        if (!isPossible) {
            return false;
        }

        // dp
        vector<unordered_set<int>> dp(m + 1);
        dp[0].insert(0);
        for (int num: nums) {
            for (int i = m; i >= 1; i--) {
                for (int x: dp[i - 1]) {
                    int curr = x + num;
                    if (curr * n == sum * i) {
                        return true;
                    }
                    dp[i].emplace(curr);
                } 
            }
        }
        return false;
    }
};
// @lc code=end


       0       1       2        3        4
1  [  {0,1},  {1},     {1},    {1},     {1}]
2  [  {0,1},  {1},     {1},    {1},     {1}]
3
4
