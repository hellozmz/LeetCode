
#include <algorithm>
#include <climits>
#include <cfloat>
#include <numeric> // accumulate定义的头文件
#include <iostream>
#include <vector>
using namespace std;

template<class T>
void printVector(const vector<T>& vec) {
    for (const auto& item : vec) {
        cout << item << " ";
    }
    cout << endl;
}