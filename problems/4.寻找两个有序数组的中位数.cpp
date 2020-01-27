/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int l1(0), l2(0), r1(len1-1), r2(len2-1);
        int l_min, r_max;
        double mid = 0.0f;

        // 两个数组之间没有交杂在一起
        if (nums1[l1] > nums2[r2]) {
            // 中位数在num1中
            if ((len1 + len2) % 2 == 1) {
                mid = nums1[(r1+r2+1)/2-1] * 1.0;
            } else if (r1 == r2) {
                mid = (nums1[l1] + nums2[r2]) * 1.0 / 2.0;
            } else {
                mid = (nums1[(r1+r2+1)/2-1] + nums1[(r1+r2+1)/2]) * 1.0 / 2.0;
            }
            return mid;
        } else if (nums2[l2] > nums1[r1]) {
            // 中位数在num2中
            if ((len1 + len2) % 2 == 1) {
                mid = nums2[(r1+r2+1)/2-1] * 1.0;
            } else if (r1 == r2) {
                mid = (nums1[r1] + nums2[l2]) * 1.0 / 2.0;
            } else {
                mid = (nums2[(r1+r2+1)/2-1] + nums2[(r1+r2+1)/2]) * 1.0 / 2.0;
            }
            return mid;
        } else {
            // 走下面的逻辑
        }

        // 交杂在一起
        if (nums1[l1] < nums2[l2]) {
            l_min = nums1[l1++];
        } else {
            l_min = nums2[l2++];
        }
        if (nums1[r1] > nums2[r2]) {
            r_max = nums1[r1--];
        } else {
            r_max = nums2[r2--];
        }
        mid = (l_min+r_max)*1.0/2.0;

        while (l_min < r_max) {
            if (nums1[l1] < nums2[l2]) {
                l_min = nums1[l1++];
            } else {
                l_min = nums2[l2++];
            }
            if (nums1[r1] > nums2[r2]) {
                r_max = nums1[r1--];
            } else {
                r_max = nums2[r2--];
            }

            mid = (l_min+r_max)*1.0/2.0;
        }

        return mid;
    }
};
// @lc code=end

