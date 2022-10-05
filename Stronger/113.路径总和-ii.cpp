/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode.cn/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (63.23%)
 * Likes:    846
 * Dislikes: 0
 * Total Accepted:    299.2K
 * Total Submissions: 473.3K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：[[5,4,11,2],[5,8,4,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1,2], targetSum = 0
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点总数在范围 [0, 5000] 内
 * -1000 
 * -1000 
 * 
 * 
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
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> pathSum0(TreeNode* root, int targetSum) {
        vector<int> curr{};
        helper(root, targetSum, curr);
        return result;
    }

/**
 * @brief 回溯法
 * 为什么在结果相等之后，还要再pop_back()一次呢，如果不pop_back()，会导致最终列表中
 * 插入的节点个数和删除的节点个数不匹配，由于curr是引用的，结果中并看不出来最终插入的节点没有pop，
 * 反而是看到了第一次插入的节点没有pop。让大家困惑
 * 
 * @param root 
 * @param targetSum 
 * @param curr 
 */
    void helper(TreeNode* root, int targetSum, vector<int>& curr) {
        if (!root) {
            return;
        }
        // print(targetSum, curr);
        if (!root->left && !root->right && root->val == targetSum) {
            curr.push_back(targetSum);
            result.emplace_back(curr);
            curr.pop_back();        // 非常重要，如果没有这次回溯，会导致最终回溯少了一次，影响结果
            return;
        }

        if (root->left) {
            curr.push_back(root->val);
            helper(root->left, targetSum - root->val, curr);
            curr.pop_back();
        }

        if (root->right) {
            curr.push_back(root->val);
            helper(root->right, targetSum - root->val, curr);
            curr.pop_back();
        }
    }

    void print(int targetSum, vector<int>& curr) {
        cout << "=======" << targetSum << "=======" << endl;
        for (auto i : curr) {
            cout << i << " ";
        }
        cout << endl;
    }


    vector<int> path;
    vector<vector<int>> ans;
    void dfs(TreeNode* root,int sum){
        if(!root) return;
        path.push_back(root->val);
        if(!root->left&&!root->right&&sum==root->val){
            ans.push_back(path);
            return;
        }
        if(root->left){
            dfs(root->left,sum - root->val);
            path.pop_back();
        }
        if(root->right){
            dfs(root->right,sum - root->val);
            path.pop_back();
        }
        
    }
    vector<vector<int>> pathSum1(TreeNode* root, int sum) {
        dfs(root,sum);
        return ans;
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr{};
        helper2(root, targetSum, curr);
        return result;
    }

    void helper2(TreeNode* root, int targetSum, vector<int>& curr) {
        if (!root) {
            return;
        }
        curr.push_back(root->val);
        if (!root->left && !root->right && root->val == targetSum) {
            result.emplace_back(curr);
            // curr.pop_back();        // 非常重要，如果没有这次回溯，会导致最终回溯少了一次，影响结果
            return;
        }

        if (root->left) {
            // curr.push_back(root->val);
            helper(root->left, targetSum - root->val, curr);
            curr.pop_back();
        }

        if (root->right) {
            // curr.push_back(root->val);
            helper(root->right, targetSum - root->val, curr);
            curr.pop_back();
        }
    }
    /**
     * 仔细看了下代码，对整体理解的更好了，主要是比较helper2和helper
     * 中间相差了两句话：插入数据的位置，pop_back的位置
     * 在helper中，是只有进入了if语句才会加入节点，这里又个细节，就是在叶子节点的时候是还没进去就加入了节点信息
     * 所以要在叶子节点中加一句pop_back;
     * 在helper2中是，不管进哪个节点都加入了节点，这样，从最下面来看，只右左右节点会进入，所以只在左右节点中pop下
     * 在curr中永远有一个根节点
     * 
     */
};
// @lc code=end

