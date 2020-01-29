#include <iostream>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
    }

    // 根据输入的有序数组和目标，返回目标的下标。
    // 数组中不包含目标值，则返回-1；存在则返回任意一个下标
    int BinarySearch(vector<int>& nums, int target) {
        if (nums.size() == 0)   return -1;
        int left(0), right(nums.size()-1);  // l/r是闭区间
        while (left <= right) {     // 相等的时候也要执行，判断最后一个元素
            int mid = (left + right) / 2;   // 向下取整，即左边界
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

int main() {
    std::vector<int> nums{1,2,2,2,3};
    int target = 2;
    Solution s;
    std::cout << s.BinarySearch(nums, target) << std::endl;
    return 0;
}

