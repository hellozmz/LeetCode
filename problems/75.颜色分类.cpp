/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (54.33%)
 * Likes:    311
 * Dislikes: 0
 * Total Accepted:    53.4K
 * Total Submissions: 98.2K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 注意:
 * 不能使用代码库中的排序函数来解决这道题。
 * 
 * 示例:
 * 
 * 输入: [2,0,2,1,1,0]
 * 输出: [0,0,1,1,2,2]
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用计数排序的两趟扫描算法。
 * 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int index0 = 0;
        int index2 = size - 1;
        int cur = 0;
        while (cur <= index2) {
            if (nums[cur] == 0) {
                swap(nums, cur, index0);
                ++index0;
                ++cur;
            } else if (nums[cur] == 2) {
                // 注意这里的操作，当当前数据是2的时候，不要更新当前的cur指针，当前的数据还需要处理一下
                swap(nums, cur, index2);
                --index2;
            } else {
                ++cur;
            }
            
            // cout << "cur=" << cur << ", index0=" << index0 << ", index2=" << index2 << endl;
        }
        return;
    }

    void sortColors_old(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) {
            return;
        }
        int p0 = 0, cur = p0, p2 = len - 1;
        while (cur <= p2) {
            if (nums[cur] == 2) {
                nums[cur] = nums[p2];
                nums[p2] = 2;
                --p2;
                // ++cur;
            } else if (nums[cur] == 0) {
                nums[cur] = nums[p0];
                nums[p0] = 0;
                ++p0;
                ++cur;
            } else {
                ++cur;
            }
            // for (auto e : nums) {
            //     std::cout << e << " ";
            // }
            // std::cout << std::endl;
        }
        return;
    }
};
// @lc code=end

