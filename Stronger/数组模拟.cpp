#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief 输出一个数组
 * 1 2 6  7
 * 3 5 8  11
 * 4 9 10 12
 * 
 * @param n 
 * @param m 
 */
void test1(int n, int m) {
    vector<vector<int>> result(n, vector<int>(m, 0));
    int count = 1;
    int i = 0, j = 0;
    int flag = -1;      // -1代表从左下向右上，1代表右上向左下
    while (i < n && j < m) {
        result[i][j] = count++;
        if (flag > 0) {
            ++i;
            --j;
        } else {
            ++j;
            --i;
        }

        // 处理边界
        // 上
        if (i < 0) {
            i = 0;
            flag = 1;
        }
        // 下
        if (i == n) {
            i = n-1;
            j += 2;
            flag = -1;
        }
        // 左
        if (j < 0) {
            j = 0;
            flag = -1;
        }
        // 右
        if (j == m) {
            i += 2;
            j = m-1;
            flag = 1;
        }
    }

    for (auto& v : result) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n = 3, m = 4;
    test1(n, m);
    return 0;
}