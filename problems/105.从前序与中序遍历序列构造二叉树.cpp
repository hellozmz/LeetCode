/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (63.70%)
 * Likes:    317
 * Dislikes: 0
 * Total Accepted:    39.4K
 * Total Submissions: 61.8K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    unordered_map<int, int> inorder_index;
    TreeNode* helper(vector<int>& preorder, int p_start, int p_end,
                     vector<int>& inorder, int i_start, int i_end) {
        if (p_start > p_end) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[p_start]);
        // auto iter = std::find(inorder.begin() + i_start,
        //                       inorder.begin() + i_end + 1,
        //                       root->val);
        // int index = std::distance(inorder.begin(), iter);
        // 通过提前构建索引，可以加快处理速度
        int index = inorder_index[root->val];
        root->left = helper(preorder, p_start + 1, index - i_start + p_start,
                            inorder, i_start, index - 1);
        root->right = helper(preorder, p_start + index - i_start + 1, p_end,
                             inorder, index + 1, i_end);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = nullptr;
        int len = preorder.size();
        if (preorder.size() != inorder.size() || preorder.empty()) {
            return root;
        }
        for (int i = 0; i < len; ++i) {
            inorder_index[inorder[i]] = i;
        }
        return helper(preorder, 0, len-1, inorder, 0, len-1);
    }
};
// @lc code=end

