/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 *
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (55.76%)
 * Likes:    885
 * Dislikes: 0
 * Total Accepted:    170.7K
 * Total Submissions: 305.5K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
 * 
 * 
 * 
 * 示例 :
 * 给定二叉树
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
 * 
 * 
 * 
 * 注意：两结点之间的路径长度是以它们之间边的数目表示。
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
    int diameterOfBinaryTree0(TreeNode* root) {
        int length = 0;
        if (root == nullptr) {
            return length;
        }
        getMax(root, length);
        return length;
    }

    void getMax(TreeNode *root, int &length) {
        int left = len(root->left);
        int right = len(root->right);
        length = std::max(length, left + right);
    }

    int len(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(len(root->left), len(root->right)) + 1;
    }

    int ans=0;

int height(TreeNode* root)
{
    if(!root) return 0;
    
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    
    ans= max(ans, lHeight + rHeight);
    return 1+ max( lHeight , rHeight);

}

int diameterOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    height(root);
    return ans;
}

};
// @lc code=end

