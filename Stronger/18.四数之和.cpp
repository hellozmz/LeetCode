/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode.cn/problems/4sum/description/
 *
 * algorithms
 * Medium (38.04%)
 * Likes:    1388
 * Dislikes: 0
 * Total Accepted:    375.3K
 * Total Submissions: 987.1K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a],
 * nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 * 
 * 
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * 
 * 
 * 你可以按 任意顺序 返回答案 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int a = 0, b = 0, c = 0, d = 0;
        int len = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (; a < len - 3; ++a) {
            if (a != 0 && nums[a] == nums[a - 1]) {
                continue;
            }
            for (b = a + 1; b < len - 2; ++b) {
                if (b != a + 1 && nums[b] == nums[b - 1]) {
                    continue;
                }
                c = b + 1;
                d = len - 1;
                while (c < d) {
                    long sum = (long) nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum == target) {
                        result.push_back({nums[a], nums[b], nums[c], nums[d]});
                        ++c;
                        while (c < d && nums[c] == nums[c - 1]) {
                            ++c;
                        }
                        --d;
                        while (c < d && nums[d] == nums[d + 1]) {
                            --d;
                        }
                    } else if (sum < target) {
                        ++c;
                    } else {
                        --d;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

