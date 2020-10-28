/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (60.63%)
 * Likes:    345
 * Dislikes: 0
 * Total Accepted:    72.8K
 * Total Submissions: 120.1K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // swap
        //         swap(nums[begin], nums[rand() % (end - begin + 1) + begin]);
        // int pos = rand() % nums.size();
        // int tmp = nums[pos];
        // nums[pos] = nums[0];
        // nums[0] = tmp;
        int index = nums.size() - k;
        quick_select(nums, 0, nums.size() -1, nums.size() - k);
        return nums[index];
    }

    int findKthLargest_old(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 0; i < nums.size(); ++i) {
            if (pq.size() < k) {
                pq.push(nums[i]);
            } else if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }

    int partition(vector<int>& nums, int low, int high) {
        /**
         * 找到一个元素的最终位置，并且可以根据当前的数字将数组分成对应的两部分
         * 最开始需要将low指定的位置的数字保存起来，放在了value中。这个操作和swap需要引入一个临时变量是一样的
        */
        int value = nums[low];
        while (low < high) {
            while (low < high && nums[high] >= value)    --high;
            nums[low] = nums[high];
            while (low < high && nums[low] <= value)     ++low;
            nums[high] = nums[low];
        }
        nums[low] = value;
        return low;
    }

    bool quick_select(vector<int>& nums, int low, int high, int index) {
        if (low < high) {
            int pos = partition(nums, low, high);
            if (pos == index) {
                // cout << "pos = " << pos << endl;
                // cout << "value = " << nums[pos] << endl;
                return true;
            }
            quick_select(nums, low, pos - 1, index);
            quick_select(nums, pos + 1, high, index);
        }
        return false;
    }

    void quick_sort(std::vector<int>& nums, int low, int high) {
        if (low < high) {
            int position = partition(nums, low, high);
            cout << "position = " << position << endl;
            quick_sort(nums, low, position - 1);
            quick_sort(nums, position + 1, high);
        }
    }
};
// @lc code=end

int main() {
    vector<int> nums{5, 3, 7, 2, 4, 1};
    Solution s;
    cout << " begin "<< endl;
    s.quick_sort(nums, 0, nums.size() -1);
    for (auto elem : nums) {
        cout << elem << " ";
    }
    cout << endl;
    cout << " end "<< endl;
    return 0;
}
