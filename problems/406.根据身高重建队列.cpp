/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 *
 * https://leetcode-cn.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (61.37%)
 * Likes:    218
 * Dislikes: 0
 * Total Accepted:    15.2K
 * Total Submissions: 24.7K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。
 * 编写一个算法来重建这个队列。
 * 
 * 注意：
 * 总人数少于1100人。
 * 
 * 示例
 * 
 * 
 * 输入:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * 
 * 输出:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int len = people.size();
        if (len < 2) {
            return people;
        }
        std::sort(people.begin(), people.end(), [](std::vector<int>&a, std::vector<int>&b) {
            if (a[0] != b[0]) {
                return a[0] > b[0];
            } else {
                return a[1] < b[1];
            }
        });

        std::list<vector<int>> ans;
        for (int i = 0; i < len; ++i) {
            auto pos = ans.begin();
            std::advance(pos, people[i][1]);
            ans.insert(pos, people[i]);
        }
        
        return std::vector<std::vector<int>>(ans.begin(), ans.end());
    }
};
// @lc code=end

