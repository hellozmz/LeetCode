/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 *
 * https://leetcode-cn.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (60.78%)
 * Likes:    1127
 * Dislikes: 0
 * Total Accepted:    149.5K
 * Total Submissions: 246K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
 * 
 * 除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果
 * 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
 * 
 * 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 
 * 
 * 输入: root = [3,2,3,null,3,null,1]
 * 输出: 7 
 * 解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
 * 
 * 示例 2:
 * 
 * 
 * 
 * 
 * 输入: root = [3,4,5,1,3,null,1]
 * 输出: 9
 * 解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 
 * 
 * 树的节点数在 [1, 10^4] 范围内
 * 0 <= Node.val <= 10^4
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
    int rob0(TreeNode* root) {
        if (!root) {
            return 0;
        } else if (!root->left && !root->right) {
            return root->val;
        }

        int result = 0;
        vector<int> path;

        rotTree(result, path, root);

        return result;
    }

    void rotTree(int& result, vector<int>& path, TreeNode* root) {
        if (!root) {
            return;
        }

        if (path.size() > 1) {
            result = max(path.back(), path[path.size() - 2] + root->val);
        }
        
        path.push_back(root->val);

        rotTree(result, path, root->left);
        rotTree(result, path, root->right);

        path.pop_back();
    }

    unordered_map<TreeNode* , int> umap; // 记录计算过的结果
    /**
     * @brief 暴力方法
     * 
     * @param root 
     * @return int 
     */
    int rob1(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return root->val;
        }
        if (umap.count(root)) {
            return umap[root];
        }

        int val1 =0, val2 = 0;
        // 偷root
        val1 += root->val;
        if (root->left) {
            val1 += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            val1 += rob(root->right->left) + rob(root->right->right);
        }

        // 不偷root
        val2 += rob(root->left) + rob(root->right);

        umap[root] = max(val1, val2);
        return umap[root];
    }

    /**
     * @brief 动态规划
     * 
     * @param root 
     * @return int 
     */
    int rob(TreeNode* root) {
        auto result = robTree2(root);
        return max(result[0], result[1]);
    }

    /**
     * @brief 
     * 
     * @param root 
     * @return int 
     */
    vector<int> robTree2(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        // 后序遍历的方式
        vector<int> left = robTree2(root->left);
        vector<int> right = robTree2(root->right);

        int noCurr = 0, containCurr = 0;
        containCurr = root->val + left[0] + right[0];

        noCurr = max(left[0], left[1]) + max(right[0], right[1]);

        return {noCurr, containCurr};
    }
};
// @lc code=end

