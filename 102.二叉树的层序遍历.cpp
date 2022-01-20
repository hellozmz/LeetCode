/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (64.25%)
 * Likes:    1154
 * Dislikes: 0
 * Total Accepted:    461.7K
 * Total Submissions: 718.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：[[1]]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> queue;
        std::vector<std::vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue.push(root);
        while (!queue.empty()) {
            std::queue<TreeNode*> tmp_queue = queue;
            std::vector<int> level;
            while (!tmp_queue.empty()) {
                auto top = tmp_queue.front();
                level.push_back(top->val);
                tmp_queue.pop();
                queue.pop();
                if (top->left) {
                    queue.push(top->left);
                }
                if (top->right) {
                    queue.push(top->right);
                }
            }
            result.emplace_back(level);
        }
        return result;
    }
};
// @lc code=end

