/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.53%)
 * Likes:    848
 * Dislikes: 0
 * Total Accepted:    233.7K
 * Total Submissions: 322.3K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历，
 * postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * 输出：[3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入：inorder = [-1], postorder = [-1]
 * 输出：[-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder 和 postorder 都由 不同 的值组成
 * postorder 中每一个值都在 inorder 中
 * inorder 保证是树的中序遍历
 * postorder 保证是树的后序遍历
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 根据后序，从后向前，找到根节点，在中序遍历中找到左右
        int postIndex = postorder.size() - 1;
        return dfs(inorder, 0, postIndex, postorder, 0, postIndex);
    }

    // 应该使用递归的方法，ib/ie是中序中左右边界，闭区间
    TreeNode* dfs(vector<int>& inorder, int ib, int ie, vector<int>& postorder,
                  int pb, int pe) {
        // 如果中序没有空间，则没数据了
        if (ib > ie) {
            return nullptr;
        } else if (ib == ie) {
            return new TreeNode(inorder[ib]);
        } else {
            // 有多个节点，需要递归
            int value = postorder[pe];
            TreeNode* root = new TreeNode(value);
            for (int i = ib; i <= ie; ++i) {
                if (inorder[i] == value) {
                    root->left = dfs(inorder, ib, i - 1, postorder, pb,
                                     pb + (i - ib - 1));
                    root->right = dfs(inorder, i + 1, ie, postorder,
                                      pb + (i - ib), pe - 1);
                    break;
                }
            }
            return root;
        }
    }
};
// @lc code=end
