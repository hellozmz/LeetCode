/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (70.68%)
 * Likes:    1384
 * Dislikes: 0
 * Total Accepted:    287.8K
 * Total Submissions: 406.9K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 *   3
 * 9  20
 *   15 7
 * 
 * 示例 2:
 * 
 * 
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * inorder.length == preorder.length
 * -3000 
 * preorder 和 inorder 均无重复元素
 * inorder 均出现在 preorder
 * preorder 保证为二叉树的前序遍历序列
 * inorder 保证为二叉树的中序遍历序列
 * 
 * TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
    if(ps > pe){
        return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[ps]);
    int pos;
    for(int i = is; i <= ie; i++){
        if(inorder[i] == node->val){
            pos = i;
            break;
        }
    }
    node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
    node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
    return node;
}
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
TreeNode *buildTree0(vector<int> &preorder, vector<int> &inorder) {
    return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
    if(ps > pe){
        return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[ps]);
    int pos;
    for(int i = is; i <= ie; i++){
        if(inorder[i] == node->val){
            pos = i;
            break;
        }
    }
    node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
    node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
    return node;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 采用递归的方式处理
        std::unordered_map<int, int> index;                 // 记录中序每个元素的下标
        for (int i = 0; i < inorder.size(); ++i) {
            index[inorder[i]] = i;
        }
        return create0(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, index);
    }

    // 两边的元素都算在内
    TreeNode *create0(std::vector<int> &pre, int ps, int pe, std::vector<int> &in, int is, int ie, std::unordered_map<int, int> &index) {
        if (ps > pe) {
            // 说明已经没有元素可以使用了
            return nullptr;
        }
        // 头节点在中序遍历中的位置
        int pos = index[pre[ps]];
        TreeNode *node = new TreeNode(pre[ps]);
        // 记录左子树的长度
        int len = pos - is + 1;
        // 构造左子树
        node->left = create0(pre, ps + 1, ps + len - 1, in, is, pos - 1, index);
        // 构造右子树
        node->right = create0(pre, ps + len, pe, in, pos + 1, ie, index);
        return node;
    }
};
// @lc code=end

