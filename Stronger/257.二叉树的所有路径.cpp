/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode.cn/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (70.33%)
 * Likes:    823
 * Dislikes: 0
 * Total Accepted:    253.9K
 * Total Submissions: 361K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1]
 * 输出：["1"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
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
    vector<string> binaryTreePaths0(TreeNode* root) {
        vector<string> result;
        helper(root, "", result);
        return result;
    }

    void helper(TreeNode* root, string str, vector<string>& result) {
        if (!root) {
            return;
        }
        if (!str.empty()) {
            str += "->";
        }
        str += to_string(root->val);
        if (!root->left && !root->right) {
            result.emplace_back(str);
        }
        helper(root->left, str, result);
        helper(root->right, str, result);
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path = "";
        bt(root, path, result);
        return result;
    }

    void bt(TreeNode* root, string path, vector<string>& result) {
        if (!root) {
            return;
        }

        // fill
        string localStr = "";
        if (!path.empty()) {
            localStr = "->";
        }
        localStr += (std::to_string(root->val));

        if (!root->left && !root->right) {
            result.emplace_back(path + localStr);
        }

        bt(root->left, path + localStr, result);
        bt(root->right, path + localStr, result);
    }
};
// @lc code=end

