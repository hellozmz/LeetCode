/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode.cn/problems/3sum/description/
 *
 * algorithms
 * Medium (35.75%)
 * Likes:    5023
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^5 
 * 
 * 
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// 暴力法，直接O(n3)的复杂度
class Solution0 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        if (len < 3 || nums[0] > 0 || nums[len - 1] < 0) {
            return result;
        }
        if (nums[0] == 0 && nums[len - 1] == 0) {
            return {{0, 0, 0}};
        }
        for (int i = 0; i < len; ++i) {
            if (i > 0 && nums[i] == nums[i - 1] || nums[i] > 0) {
                continue;
            }
            for (int j = i + 1; j < len; ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue;;
                }
                for (int k = j + 1; k < len; ++k) {
                    if (k != j + 1 && nums[k] == nums[k - 1]) {
                        continue;;
                    }
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        result.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        if (len < 3 || nums[0] > 0 || nums[len - 1] < 0) {
            return result;
        }
        if (nums[0] == 0 && nums[len - 1] == 0) {
            return {{0, 0, 0}};
        }

        for (int first = 0; first < len; ++first) {
            if (nums[first] > 0) {
                return result;
            }
            if (nums[first] > 0) {
                break;
            }
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }

            int second = first + 1;
            int third = len - 1;
            while (second < third) {
                // if (second > first + 1 && nums[second] == nums[second - 1]) {
                //     ++second;
                //     continue;
                // }
                // if (third < len - 1 && nums[third] == nums[third + 1]) {
                //     --third;
                //     continue;
                // }
                if (nums[first] + nums[second] + nums[third] == 0) {
                    result.push_back({nums[first], nums[second], nums[third]});
                    ++second;
                    // 将外部的continue动作放到这里写成while循环，减少判断的语句。
                    // 这里的判断特别有一种快排的感觉
                    while (second < third && nums[second] == nums[second - 1]) {
                        ++second;
                    }
                    --third;
                    while (second < third && nums[third] == nums[third + 1]) {
                        --third;
                    }
                } else if (nums[first] + nums[second] + nums[third] < 0) {
                    ++second;
                } else {
                    --third;
                }
            }
        }
        return result;
    }
};
// @lc code=end


int main() {
    Solution s;
    std::vector<int> nums = {-1, 0, 1};
    s.threeSum(nums);
}