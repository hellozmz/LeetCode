/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 *
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (46.75%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    17.4K
 * Total Submissions: 37.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
 * 
 * 示例 :
 * 给定二叉树
 * 
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
 * 注意：两结点之间的路径长度是以它们之间边的数目表示。
 * 
 * 使用了递归的时候，尽量不要在递归的里面继续使用递归了，否砸耗时比较严重
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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int diameter = 0;
        SuperDepth(root, &diameter);
        return diameter;
    }

    int SuperDepth(TreeNode* root, int* diameter) {
        if (!root) {
            return 0;
        }
        int left = SuperDepth(root->left, diameter);
        int right = SuperDepth(root->right, diameter);

        *diameter = std::max(left + right, *diameter);

        return std::max(left, right) + 1;
    }

    int diameterOfBinaryTree1(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int diameter = 0;
        int left_depth = depth(root->left);
        int right_depth = depth(root->right);
        diameter = left_depth + right_depth;

        int left_diameter = diameterOfBinaryTree(root->left);
        int right_diameter = diameterOfBinaryTree(root->right);

        // std::cout << "root=" << root->val
        //             << ", diameter=" << diameter
        //             << ", left_diameter=" << left_diameter
        //             << ", right_diameter=" << right_diameter
        //             << ", left_depth=" << left_depth
        //             << ", right_depth=" << right_depth
        //             << std::endl;

        return std::max({left_diameter, right_diameter, diameter});
    }

    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return std::max(depth(root->left), depth(root->right)) + 1;
    }
};
// @lc code=end

