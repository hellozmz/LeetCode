/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 * 1.需要注意，不能使用同一个整数去组成目标值
 * 2.为了提高速度，尽量使用一些数据结构比如map去加快搜索
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> nums_index;
        for (int i=0; i<nums.size(); ++i) {
            nums_index[nums[i]] = i;
        }
        for (int i=0; i<nums.size(); ++i) {
            int remain_num = target - nums[i];
            // cout << "remain_num=" << remain_num
            //      << "\nnums[i]=" << nums[i];
            if (nums_index.find(remain_num) != nums_index.end()) {
                if (i == nums_index[remain_num]) {
                    continue;
                }
                return std::vector<int>({i, nums_index[remain_num]});
            }
        }
        return std::vector<int>({0, 0});
    }
};
// @lc code=end

