#include <iostream>
#include <vector>

class Solution {
 public:
    std::vector<int> solution(std::vector<int>& input) {
        int size = input.size();
        std::vector<int> result(size);
        if (size == 0) {
            return result;
        }
        std::sort(input.begin(), input.end());
        int begin = 0, end = size - 1;
        int left_sum = 0, right_sum = 0;
        bool left = true;
        for (int i = 0; i < size; ++i) {
            if (left) {
                left_sum += input[i];
                result[begin++] = input[i];
            } else {
                right_sum += input[i];
                result[end--] = input[i];
            }
            left = left_sum > right_sum ? false : true;
        }
        return result;
    }
};

int main() {
    std::vector<int> input{1, 4, 5, 23, 2, 17, 24, 1000000};
    Solution s;
    auto v = s.solution(input);
    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
