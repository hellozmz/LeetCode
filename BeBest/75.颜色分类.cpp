/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (59.89%)
 * Likes:    1116
 * Dislikes: 0
 * Total Accepted:    303.5K
 * Total Submissions: 506.2K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,0,2,1,1,0]
 * 输出：[0,0,1,1,2,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,0,1]
 * 输出：[0,1,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[0]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 
 * nums[i] 为 0、1 或 2
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以不使用代码库中的排序函数来解决这道题吗？
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 因为限定了3个数字，因此可以考虑双指针
        int left = 0, right = nums.size() - 1;
        int index = 0;      // 真正遍历过程中的元素索引
        while (index <= right) {
            if (nums[index] == 0) {
                // nums[left++] = 0;
                // 接下来处理下一个位置，因此index++
                std::swap(nums[left++], nums[index++]);
            } else if (nums[index] == 1) {
                ++index;
            } else if (nums[index] == 2) {
                // nums[right--] = 2;
                // std::swap(nums[right--], nums[index++]);
                // 注意：index不需要再更新了，因为这里都是交换的操作，不是赋值
                // index 是从左向右走动的👉，index的位置数据不一定是正确的，还需要处理，因此不能index++
                std::swap(nums[right--], nums[index]);
            }
            // ++index;
        }
        // while (left < right) {
        //     nums[left++] = 1;
        // }
    }

    // 答案
    void sortColors0(vector<int>& nums) {
        int i = 0, j = i, k = nums.size() - 1;
        
        while(j <= k){
            if(nums[j] == 0) swap(nums[i++], nums[j++]);
            else if(nums[j] == 1) j++;
            else swap(nums[k--], nums[j]);
        }
    }
};
// @lc code=end

