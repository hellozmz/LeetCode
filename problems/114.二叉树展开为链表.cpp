/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (67.01%)
 * Likes:    248
 * Dislikes: 0
 * Total Accepted:    24.1K
 * Total Submissions: 35.9K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preorder0(TreeNode* root, std::vector<TreeNode*>& flatten) {
        if (root) {
            flatten.push_back(root);
            preorder(root->left, flatten);
            preorder(root->right, flatten);
        }
    }

    void preorder(TreeNode* root, std::vector<TreeNode*>& flatten) {
        std::stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                flatten.push_back(root);
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            root = root->right;
        }
    }
    void flatten0(TreeNode* root) {
        std::vector<TreeNode*> tmp;
        preorder(root, tmp);
        for (int i = 1; i < tmp.size(); ++i) {
            auto* pre = tmp[i-1];
            pre->left = nullptr;
            pre->right = tmp[i];
        }
    }

    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* next = cur->left;
                TreeNode* pre_for_right = next;
                while (pre_for_right->right) {
                    pre_for_right = pre_for_right->right;
                }
                pre_for_right->right = cur->right;
                cur->left = nullptr;    // 给当前节点的左右节点都更新一遍
                cur->right = next;
            }
            cur = cur->right;
        }
    }
};
// @lc code=end

