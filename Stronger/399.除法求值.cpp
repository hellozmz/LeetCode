/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 *
 * https://leetcode.cn/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (59.30%)
 * Likes:    771
 * Dislikes: 0
 * Total Accepted:    59.2K
 * Total Submissions: 99.8K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和
 * values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
 * 
 * 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj
 * = ? 的结果作为答案。
 * 
 * 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0
 * 替代这个答案。
 * 
 * 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * 输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * 解释：
 * 条件：a / b = 2.0, b / c = 3.0
 * 问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * 结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0],
 * queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * 输出：[3.75000,0.40000,5.00000,0.20000]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * 输出：[0.50000,2.00000,-1.00000,-1.00000]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * equations[i].length == 2
 * 1 i.length, Bi.length 
 * values.length == equations.length
 * 0.0 < values[i] 
 * 1 
 * queries[i].length == 2
 * 1 j.length, Dj.length 
 * Ai, Bi, Cj, Dj 由小写英文字母与数字组成
 * 
 * 
 */

// @lc code=start
class f {
public:
    f() {}
    f(std::string x, std::string y, double z): a(x), b(y), v(z) {}
    std::string a;
    std::string b;
    double v = -1.0;
};

class Solution0 {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int len = equations.size();
        std::unordered_multimap<std::string, f> eqs;
        for (int i = 0; i < len; ++i) {
            auto& e = equations[i];
            // eqs[e[0]] = f(e[0], e[1], values[i]);
            // eqs[e[1]] = f(e[1], e[0], 1.0 / values[i]);
            eqs.insert(std::pair<std::string, f>(e[0], f(e[0], e[1], values[i])));
            eqs.insert(std::pair<std::string, f>(e[1], f(e[1], e[0], 1.0 / values[i])));
        }

        std::vector<double> result;
        for (auto& q : queries) {
            std::string x = q[0];
            std::string y = q[1];
            std::unordered_set<std::string> visited;
            result.push_back(getValue(x, y, eqs, visited));
        }
        return result;
    }

    double getValue(std::string a, std::string& b, const std::unordered_multimap<std::string, f>& eqs, std::unordered_set<std::string>& visited) {
        double value = 1.0;
        while (eqs.count(a) > 0) {
            if (visited.count(a) > 0) {
                return -1.0;
            }
            visited.insert(a);
            auto find_a = eqs.find(a);
            int count = 0;
            while (find_a != eqs.end()) {
                count++;
                if (find_a->second.b == b) {
                    value *= find_a->second.v;
                    return value;
                } else {
                    value *= getValue(a, b, eqs, visited);
                    if (value < 0.0 && count == eqs.count(a)) {
                        std::cout << "a=" << a << ", b=" << b <<  ", count=" << count << ", eqs.count(a)=" << eqs.count(a) << std::endl;
                        return -1.0;
                    }
                }
                find_a++;
            }

            // if (eqs.at(a).b == b) {
            //     value *= eqs.at(a).v;
            //     return value;
            // }
            a = find_a->second.b;
        }
        return -1.0;
    }
};

class Solution1 {
public:
    int findf(vector<int>& f, vector<double>& w, int x) {
        if (f[x] != x) {
            int father = findf(f, w, f[x]);
            w[x] = w[x] * w[f[x]];
            f[x] = father;
        }
        return f[x];
    }

    void merge(vector<int>& f, vector<double>& w, int x, int y, double val) {
        int fx = findf(f, w, x);
        int fy = findf(f, w, y);
        f[fx] = fy;
        w[fx] = val * w[y] / w[x];
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nvars = 0;
        unordered_map<string, int> variables;

        // 构建有向图
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            if (variables.find(equations[i][0]) == variables.end()) {
                variables[equations[i][0]] = nvars++;
            }
            if (variables.find(equations[i][1]) == variables.end()) {
                variables[equations[i][1]] = nvars++;
            }
        }
        vector<int> f(nvars);                   // 给每个节点编号
        vector<double> w(nvars, 1.0);           // 记录权重
        for (int i = 0; i < nvars; i++) {
            f[i] = i;
        }

        // 压缩路径
        for (int i = 0; i < n; i++) {
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            merge(f, w, va, vb, values[i]);
        }

        // 处理请求数据
        vector<double> ret;
        for (const auto& q: queries) {
            double result = -1.0;
            if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end()) {
                int ia = variables[q[0]], ib = variables[q[1]];
                int fa = findf(f, w, ia), fb = findf(f, w, ib);
                if (fa == fb) {
                    result = w[ia] / w[ib];
                }
            }
            ret.push_back(result);
        }
        return ret;
    }
};

class Solution {
struct Node {
    Node* parent;
    double value = 1.0;

    Node() {
        this->parent = this;
    }

    Node(double val) {
        this->value = val;
        this->parent = this;
    }

    Node(double val, Node* parent) {
        this->parent = parent;
        this->value = val;
    }
};

private:
    std::unordered_map<std::string, Node*> mapping;             // 根据名字找到对应的节点
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        std::vector<double> result;
        int len = equations.size();

        for (int i = 0; i < len; ++i) {
            std::string a = equations[i][0];
            std::string b = equations[i][1];
            double val = values.at(i);
            // todo 构建集合
            if (mapping.count(b) > 0 && mapping.count(a) == 0) {
                mapping[a] = new Node(val, mapping[b]);
            } else if (mapping.count(b) > 0 && mapping.count(a) > 0) {
                // 注意，这里需要将两个集合合并起来，由于a是分子，让b仍然作为原来的根节点，把a树都合并进去
                merge(a, b, val);
            } else if (mapping.count(b) == 0 && mapping.count(a) == 0) {
                mapping[b] = new Node();
                mapping[a] = new Node(val, mapping[b]);
            } else if (mapping.count(b) == 0 && mapping.count(a) > 0) {
                double ratio = mapping[a]->value / val;       // 用原来a所在的集合去合入b(b没有集合，只有一个节点)
                mapping[b] = new Node(ratio, mapping[a]->parent);
            }
        }

        // 获取到返回的结果
        for (int i = 0; i < queries.size(); ++i) {
            std::string a = queries[i][0];
            std::string b = queries[i][1];

            if (mapping.count(a) > 0 && mapping.count(b) > 0 && findParent(mapping[a]) == findParent(mapping[b])) {
                result.push_back(mapping.at(a)->value / mapping.at(b)->value);
            } else {
                result.push_back(-1.0);
            }
        }
        return result;
    }

    void merge(std::string a, std::string b, double v) {
        Node* na = mapping[a];
        Node* nb = mapping[b];
        double ratio = v / (na->value * nb->value);
        if (na->parent == nb) {
            return;
        }
        for (auto item : mapping) {
            if (item.second->parent == na->parent) {
                item.second->parent = nb->parent;
                item.second->value *= ratio;
            }
        }
    }

    Node* findParent(Node* node) {
        while (node->parent != node) {
            node = node->parent;
        }
        return node;
    }
};
// @lc code=end

