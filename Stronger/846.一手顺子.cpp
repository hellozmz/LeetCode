/*
 * @lc app=leetcode.cn id=846 lang=cpp
 *
 * [846] 一手顺子
 *
 * https://leetcode.cn/problems/hand-of-straights/description/
 *
 * algorithms
 * Medium (57.33%)
 * Likes:    223
 * Dislikes: 0
 * Total Accepted:    38.4K
 * Total Submissions: 66.9K
 * Testcase Example:  '[1,2,3,6,2,3,4,7,8]\n3'
 *
 * Alice 手中有一把牌，她想要重新排列这些牌，分成若干组，使每一组的牌数都是 groupSize ，并且由 groupSize 张连续的牌组成。
 * 
 * 给你一个整数数组 hand 其中 hand[i] 是写在第 i 张牌，和一个整数 groupSize 。如果她可能重新排列这些牌，返回 true
 * ；否则，返回 false 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
 * 输出：true
 * 解释：Alice 手中的牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
 * 
 * 示例 2：
 * 
 * 
 * 输入：hand = [1,2,3,4,5], groupSize = 4
 * 输出：false
 * 解释：Alice 手中的牌无法被重新排列成几个大小为 4 的组。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= hand.length <= 10^4
 * 0 <= hand[i] <= 10^9
 * 1 <= groupSize <= hand.length
 * 
 * 
 * 
 * 
 * 注意：此题目与 1296
 * 重复：https://leetcode-cn.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
 * 
 */

// @lc code=start
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int len = hand.size();
        if (len % groupSize) {
            return false;
        }
        unordered_map<int, int> umap;
        for (auto i : hand) {
            ++umap[i];
        }

        sort(hand.begin(), hand.end());

        for (auto i : hand) {
            if (umap.count(i) > 0 && umap[i] != 0) {
                for (int j = 0; j < groupSize; ++j) {
                    if (umap.count(i + j) > 0 && umap[i + j] != 0) {
                        --umap[i + j];
                    } else {
                        return false;
                    }
                }
            } else {
                continue;
            }
        }
        return true;
    }
};
// @lc code=end

