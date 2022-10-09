#include "./416.分割等和子集.cpp"

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int main() {
    Solution s;
    vector<int> input{2,2,3,5};
    vector<int> input1{14,9,8,4,3,2};
    bool result = s.canPartition(input);
    cout << boolalpha << result << endl;
}