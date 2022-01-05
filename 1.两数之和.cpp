/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int length = nums.size();
        std::unordered_map<int, int> index;     // value, index
        for (int i = 0; i < length; ++i) {
            index[nums[i]] = i;
        }
        for (int i = 0; i < length; ++i) {
            int other = target - nums[i];
            if (index.count(other) > 0 && index[other] != i) {
                result.push_back(i);
                result.push_back(index[other]);
                break;
            }
        }
        return result;
    }

    vector<int> twoSum0(vector<int>& nums, int target) {
        std::map<int, int> index_map;
        for (int i = 0; i < nums.size(); ++i) {
            index_map[nums[i]] = i;
        }
        // for (auto &item : index_map) {
        //     std::cout << item.first << ", " << item.second << std::endl;
        // }
        for (int i = 0; i < nums.size(); ++i) {
            // std::cout << target - nums[i] << ", " << i << std::endl;
            if (index_map.find(target - nums[i]) != index_map.end() && index_map[target - nums[i]] != i) {
                std::vector<int> l{i, index_map[target - nums[i]]};
                return l;
            }
        }
        std::vector<int> l;
        return l;
    }

    vector<int> twoSum1(vector<int>& nums, int target) {
        std::unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); ++i) {
            index[nums[i]] = i;
        }
        std::vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int other = target - nums[i];
            if ((index.count(other) > 0) && index[other] != i) {
                result.push_back(i);
                result.push_back(index[other]);
                return result;
            }
        }
        return result;
    }
};
// @lc code=end

