#include "../../Stronger/header.hpp"

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int len = nums.size();
        int maxValue = *max_element(nums.begin(), nums.end());
        int minValue = *min_element(nums.begin(), nums.end());
        int dpLen = maxValue - minValue + 1;
        long long result = LLONG_MAX;
//         vector<vector<long long>> dp(len + 1, vector<long long>(dpLen + 1, 0));
        
//         for (int i = 1; i <= len; ++i) {
//             for (int j = 0; j <= dpLen; ++j) {
//                 long long costs = (long long)cost[i-1] * abs(j + minValue - nums[i - 1]);
//                 dp[i][j] = dp[i-1][j] + costs;
//                 // cout << "costs " << costs << ", v = " << dp[i][j] << " ";
//                 if (i == len) {
//                     result = std::min(result, dp[i][j]);
//                 }
//             }
//             // cout << endl;
//         }
        long long t = 0;
        for (int i = 0 ; i< len; ++i) {
            t += (long long)nums[i] * cost[i];
        }
        cout << "t=" << t << endl;
        
        vector<long long> dp(dpLen + 1, 0);
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j <= dpLen; ++j) {
                long long costs = (long long)cost[i-1] * abs(j + minValue - nums[i - 1]);
                dp[j] = dp[j] + costs;
                if (i == len) {
                    // if (result > dp[j]) {
                    // if (result == 4594912589593) {
                    //     cout << i << " " << j << " ";
                    // }
                    // cout << endl;
                    result = std::min(result, dp[j]);
                }
            }
        }
        cout << result << endl;
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums{484969,501605,288641,399722,348929,731019,713895,41287,813635,815040,934880,236239,790348,185584,365361,175185,865443,853636,880144,249718,207995,256680,519024,296345,525692,949580,846584,844742,780971,168897,155440};
    vector<int> cost{139808,300655,677852,979525,973937,940100,166705,43741,765049,245539,604985,495475,979677,898468,345495,874803,889715,840664,354953,483098,824276,904702,543759,930352,427092,308517,347250,401347,431755,513455,464725};
    s.minCost(nums, cost);

    return 0;
}