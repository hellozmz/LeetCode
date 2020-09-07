/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 *
 * https://leetcode-cn.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (52.94%)
 * Likes:    95
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 8.3K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * 给出方程式 A / B = k, 其中 A 和 B 均为代表字符串的变量， k
 * 是一个浮点型数字。根据已知方程式求解问题，并返回计算结果。如果结果不存在，则返回 -1.0。
 * 
 * 示例 :
 * 给定 a / b = 2.0, b / c = 3.0
 * 问题:  a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
 * 返回 [6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 
 * 输入为:  vector<pair<string, string>> equations, vector<double>& values,
 * vector<pair<string, string>> queries(方程式，方程式结果，问题方程式)， 其中 equations.size()
 * == values.size()，即方程式的长度与方程式结果长度相等（程式与结果一一对应），并且结果值均为正数。以上为方程式的描述。
 * 返回vector<double>类型。
 * 
 * 基于上述例子，输入如下：
 * 
 * 
 * equations(方程式) = [ ["a", "b"], ["b", "c"] ],
 * values(方程式结果) = [2.0, 3.0],
 * queries(问题方程式) = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x",
 * "x"] ]. 
 * 
 * 
 * 输入总是有效的。你可以假设除法运算中不会出现除数为0的情况，且不存在任何矛盾的结果。
 * 
 */

// @lc code=start
class Solution {
 private:
    struct DNode {
        double val;
        DNode* parent;
        DNode(double val) {
            this->val = val;
            this->parent = nullptr;
        }
        DNode(double val, DNode* parent) {
            this->val = val;
            this->parent = parent;
        }
    };

    DNode* find_root(DNode* cur) {
        DNode* p = nullptr;
        while (p->parent != p) {
            p = p->parent;
        }
        return p;
    }

    void merge(DNode* m, DNode* n, double value) {
        auto p1 = find_root(m);
        auto p2 = find_root(n);

        if (p1 == p2) {
            return;
        } else {
            // 默认将p2挂到p1上
            double ratio = value * n->val / m->val;
            for (auto elem : mapping) {
                if (find_root(elem) == p1) {
                    elem->val *= ratio;
                }
            }
        }
    }

 private:
    unorderde_map<DNode*, DNode*> mapping;  // key是子节点，value是父节点
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values, vector<vector<string>>& queries) {
        auto result = std::vector<double>(queries.size());
        if (euqations.size() != values.size()) {
            return result;
        }
        // 插入数据，如果发现数据已经有一个点在集合中了，就将他们merge起来
        for (int i = 0; i < equations.size(); ++i) {

        }

        // 读取请求，依次计算并记录起来

        // 返回结果
        return result;
    }
};
// @lc code=end
