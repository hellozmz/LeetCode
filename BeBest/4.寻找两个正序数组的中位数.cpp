/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (41.09%)
 * Likes:    4849
 * Dislikes: 0
 * Total Accepted:    581.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution0 {
public:
    double findMedianSortedArrays00(vector<int>& nums1, vector<int>& nums2) {
        int total=nums1.size()+nums2.size();
        if(total%2==1) return find(nums1,0,nums2,0,total/2+1);
        int left=find(nums1,0,nums2,0,total/2);
        int right=find(nums1,0,nums2,0,total/2+1);
        return (left+right)/2.0;
    }
    int find(vector<int> &nums1,int i,vector<int> &nums2,int j,int k)
    {
       
        if(nums1.size()==i) return nums2[j+k-1];//如果第一个数组为空
        if(nums1.size()-i >nums2.size()-j) return find(nums2,j,nums1,i,k);//第一个数组个数大于第二个数组个数
        if(k==1) return min(nums1[i],nums2[j]);//数组中只有一个元素

        int si=min(int(nums1.size()),i+k/2),sj=j+k/2;
        if(nums1[si-1]>nums2[sj-1]) return find(nums1,i,nums2,sj,k-(sj-j));
        else return find(nums1,si,nums2,j,k-(si-i));
    }
    
    int getKth(vector<int>& nums1, int begin1, vector<int>& nums2, int begin2, int k) {
        if (nums1.size() == begin1) {
            return nums2[begin2+k-1];
        }
        if (nums1.size() - begin1 > nums2.size() - begin2) {        // 这里要保证第二个数组长一点
            return getKth(nums2, begin2, nums1, begin1, k);
        }
        if (k == 1) {
            return std::min(nums1[begin1], nums2[begin2]);
        }

        int si = std::min((int) nums1.size(), begin1 + k / 2);
        int sj = begin2 + k / 2;
        if (nums1[si-1] > nums2[sj-1]) {
            return getKth(nums1, begin1, nums2, sj, k - (sj - begin2));
        } else {
            return getKth(nums1, si, nums2, begin2, k - (si - begin1));
        }

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int mid = (len1 + len2) / 2;
        if ((len1 + len2) % 2 == 0) {
            int left = getKth(nums1, 0, nums2, 0, mid);
            int right = getKth(nums1, 0, nums2, 0, mid + 1);
            return (left + right) / 2.0;
        } else {
            return getKth(nums1, 0, nums2, 0, mid + 1);     // 需要是下一个，k记录的是个数，而不是索引
        }
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if ((len1 + len2) % 2 == 1) {
            return getKth(nums1, 0, nums2, 0, (len1 + len2) / 2 + 1);
        } else {
            int left = getKth(nums1, 0, nums2, 0, (len1 + len2) / 2);
            int right = getKth(nums1, 0, nums2, 0, (len1 + len2) / 2 + 1);
            return (left + right) / 2.0;
        }
    }

    double getKth(std::vector<int>& nums1, int begin1, std::vector<int>& nums2, int begin2, int k) {
        // 当数组1已经到达边界，则返回数组2中第k个元素
        if (begin1 == nums1.size()) {
            return nums2[begin2 + k - 1];
        }
        // 保持数组1是比较短的，数组2相对长一些
        if (nums1.size() - begin1 > nums2.size() - begin2) {
            return getKth(nums2, begin2, nums1, begin1, k);
        }
        // 当需要获取的数据只有一个的时候，直接返回两者之间较小的
        if (k == 1) {
            return std::min(nums1[begin1], nums1[begin2]);
        }

        int next1 = std::min(begin1 + k / 2, (int) nums1.size());
        int next2 = begin2 + k / 2;
        if (nums1[next1 - 1] < nums2[next2 - 1]) {
            return getKth(nums1, next1, nums2, begin2, k - next1 + begin1);
        } else {
            return getKth(nums1, begin1, nums2, next2, k - next2 + begin2);
        }

    }
};
// @lc code=end

