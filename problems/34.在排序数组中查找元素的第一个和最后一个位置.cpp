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
    // 二分法获取左边界下标，nums不会出现空的情况，若出现，返回-1
    int Left(const vector<int>& nums, int target) {
        if (nums.size() == 0)   return -1;
        int left(0), right(nums.size());    // 为了解决左边界，使用左闭右开区间
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                right = mid;    // 为了能够准确的返回左侧下标
                                // 即使遇见了相等的情况，也要继续向左去再试探下
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            }
        }
        return left;
    }

    // 二分法获取右边界下标，nums不会出现空的情况，若出现，返回-1
    int Right(const vector<int>& nums, int target) {
        if (nums.size() == 0)   return -1;
        int left(0), right(nums.size()-1);
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            }
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)   return std::vector<int>{-1, -1};
        int left = Left(nums, target);
        int right = Right(nums, target);
        std::cout << "left=" << left << ", right=" << right << std::endl;
        if ((left < 0) || (left >= nums.size())) {
            return std::vector<int>{-1, -1};
        } else if (nums[left] != target) {
            return std::vector<int>{-1, -1};
        }
        return std::vector<int>{left, right};
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

    // 一个相当trick的方法
    vector<int> searchRange_1(vector<int> &nums, int target) {
        auto begin = lower_bound(nums.begin(), nums.end(), target);
        auto end   = upper_bound(nums.begin(), nums.end(), target);
        if (begin == end) return {-1, -1};
        return {(int)(begin - nums.begin()), (int)(end - nums.begin() - 1)};
    }
};
// @lc code=end

int main() {
    std::vector<int> nums{2, 2};
    // std::vector<int> nums{1,2,2,2,3};
    int target = 3;
    Solution s;
    std::cout << "BinarySearch="<< s.BinarySearch(nums, target) << std::endl;
    std::cout << "Left=" << s.Left(nums, target) << std::endl;
    std::cout << "Right=" << s.Right(nums, target) << std::endl;
    return 0;
}

