/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (52.21%)
 * Likes:    12880
 * Dislikes: 0
 * Total Accepted:    2.8M
 * Total Submissions: 5.3M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 
 * 你可以按任意顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * -10^9 
 * -10^9 
 * 只会存在一个有效答案
 * 
 * 
 * 进阶：你可以想出一个时间复杂度小于 O(n^2) 的算法吗？
 * 
 */

// @lc code=start
class Solution0 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); ++i) {
            mapping[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (mapping.count(target - nums[i])) {
                if (i != mapping[target - nums[i]]) {
                    return std::vector<int>{i, mapping[target - nums[i]]};
                }
            }
        }
        return {0, 0};
    }
};

class Solution {
public:
    vector<int> twoSum0(vector<int>& nums, int target) {
        std::unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); ++i) {
            mapping[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int others = target - nums[i];
            if (mapping.count(others) > 0 && mapping[others] != i) {
                return {i, mapping.at(others)};
            }
        }
        return {0, 0};
    }


/**
 * @brief unordered_multimap 用法真的是大坑
 * 
 * @param nums 
 * @param target 
 * @return vector<int> 
 */
    vector<int> twoSum1(vector<int>& nums, int target) {
        unordered_multimap<int, int> mapping;
        for (int i = 0; i < nums.size(); ++i) {
            // mapping[nums[i]] = i;
            mapping.insert({nums[i], i});
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (mapping.count(target - nums[i]) > 0) {
                // 应该使用 mapping.equal_range
                auto next = mapping.find(target-nums[i]);
                while (next != mapping.end()) {
                    // cout << "value = " << next->first << endl;
                    if (next->first != target - nums[i]) {
                        break;
                    }
                    if (next->second != i) {
                        // cout << "target = " << target << ", i = " << i << ", next = " << next->second<< ", value=" << next->first << ",expect = " << target - nums[i] << endl;
                        return vector<int>{i, next->second};
                    }
                    ++next;
                }
            }
        }
        // [1,3,4,2]  \n6
        return vector<int>{-1, -1};
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); ++i) {
            int other = target - nums[i];
            if (mapping.count(other) > 0) {
                return vector<int>{i, mapping.at(other)};
            }
            mapping[nums[i]] = i;
        }
        return vector<int>{0, 0};
    }
};
// @lc code=end

