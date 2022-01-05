/*
 * @lc app=leetcode.cn id=53 lang=golang
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (48.81%)
 * Likes:    1547
 * Dislikes: 0
 * Total Accepted:    149.7K
 * Total Submissions: 306.6K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */

// @lc code=start
func max(left int, right int) int {
	if left > right {
		return left
	} else {
		return right
	}
}

func maxSubArray(nums []int) int {
	len := len(nums)
	max_sum := nums[0]
	dp := make([]int, len)
	for i, value := range nums {
		if i == 0 {
			dp[i] = value
		} else {
			dp[i] = max(dp[i-1] + nums[i], nums[i])
			max_sum = max(dp[i], max_sum)
		}
	}
	return max_sum
}
// @lc code=end

