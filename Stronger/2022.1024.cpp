#include <cmath>
#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// https://leetcode.cn/circle/discuss/KfFr9S/

/**
 * @brief 获取到候选集合
 * 
 * @tparam T 
 * @param result 
 * @param path 
 * @param input 
 * @param count 
 * @param startIndex 
 */
template<class T>
void bt(vector<vector<T>>& result, vector<T>& path, vector<T>& input, int count, vector<bool>& used) {
    if (path.size() == count) {
        result.emplace_back(path);
        return;
    }
    for (int i = 0; i < input.size(); ++i) {
        if (used[i]) {
            continue;
        }

        used[i] = true;
        path.push_back(input[i]);
        bt(result, path, input, count, used);
        used[i] = false;
        path.pop_back();
    }
}

/**
 * @brief Get the Candidates object
 * 
 * @tparam T 
 * @param input 输入数组
 * @param count 候选集合个数
 * @return vector<T> 
 */
template<class T>
vector<vector<T>> getCandidates(vector<T>& input, int count) {
    vector<vector<T>> result;
    vector<T> path;
    vector<bool> used(input.size(), false);
    // 回溯
    bt<T>(result, path, input, count, used);

    return result;
}

long long calUnit(int a, int b, string c) {
    if (c == "+") {
        return (long long)(a + b);
    } else if (c == "-") {
        return (long long)(a - b);
    } else if (c == "*") {
        return (long long)(a * b);
    } else if (c == "//") {
        return (long long)(a / b);
    } else if (c == "|") {
        return (long long)(a | b);
    } else if (c == "&") {
        return (long long)(a & b);
    } else if (c == "^") {
        return (long long)(a ^ b);
    } else if (c == "%") {
        return (long long)(a % b);
    } else if (c == ">>") {
        return (long long)(a >> b);
    } else if (c == "<<") {
        return (long long)(a << b);
    } else if (c == "**") {
        return (long long)(pow(a, b));
    } else {
        cout << "这个符号没有处理 " << c << endl;
        return 0;
    }
}

/**
 * @brief 判断结果是否在int32范围内
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool notGood(long long value) {
    if (value > INT_MAX || value < INT_MIN) {
        return true;
    }
    return false;
}

/**
 * @brief 检查是否是有效的计算
 * 
 * @param op 运算符
 * @param value2 运算中第二个参数
 * @return true 有效的
 * @return false 无效的
 */
bool isValid(int value2, string op) {
    if (value2 == 0) {
        if (op == "%" || op == "//") {
            return false;
        }
    }
    return true;
}

/**
 * @brief 计算候选集合的计算结果
 * 
 * @param input1 
 * @param input2 
 * @return int 
 */
int calculator(vector<int>& input1, vector<string>& input2) {
    if (input1.size() != 4 || input2.size() != 3) {
        cout << "输入数据不满足要求" << endl;
        return -1;
    }
    if (!isValid(input1[1], input2[0])) {
        return -1;
    }
    long long num1 = calUnit(input1[0], input1[1], input2[0]);
    if (notGood(num1)) {
        return -1;
    }
    if (!isValid(input1[2], input2[1])) {
        return -1;
    }
    long long num2 = calUnit(num1, input1[2], input2[1]);
    if (notGood(num2)) {
        return -1;
    }
    if (!isValid(input1[3], input2[2])) {
        return -1;
    }
    long long num3 = calUnit(num2, input1[3], input2[2]);
    if (notGood(num3)) {
        return -1;
    }
    return num3;
}

/**
 * @brief 计算一组结果，查看是否满足，满足则输出
 * 
 * @param input1 
 * @param input2 
 */
bool print1024CandiUnit(vector<int>& nums, vector<string>& ops) {
    if (1024 == calculator(nums, ops)) {
        // for (auto& i : nums) {
        //     cout << i << " ";
        // }
        // cout << endl;
        // for (auto& i : ops) {
        //     cout << i << " ";
        // }
        // cout << endl;

        cout << nums[0] << ops[0]
            << nums[1] << ops[1]
            << nums[2] << ops[2]
            << nums[3] << " = 1024" << endl;

        return true;
    }
    return false;
}

/**
 * @brief 获取所有的结果未1024的计算公式
 * 
 * @param input1 
 * @param input2 
 */
void print1024Candi(vector<int>& input1, vector<string>& input2) {
    vector<vector<int>> nums = getCandidates<int>(input1, 4);
    vector<vector<string>> ops = getCandidates<string>(input2, 3);
    int count = 0;

    for (auto& n : nums) {
        for (auto& o : ops) {
            if (print1024CandiUnit(n, o)) {
                ++count;
            }
        }
    }

    cout << "总共有  " << count << "  种可能" << endl;
}

int main() {
    vector<int> input1{33,2,0,2,6,2,2,2,2,1024,955};
    vector<string> input2{"|", ">>", "^", "|", "%", "//", "+"};

    print1024Candi(input1, input2);

    return 0;
}