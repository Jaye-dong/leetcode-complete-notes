#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /* 1. dp[i] : 目标和为i的组合个数，顺序不同视为不同组合，实际上是求排列 */
        /* 2. dp[i] += dp[i - nums[j]]; 求装满背包有多少种装法的标准递推公式 */
        /* 3. dp[0] = 1; 完全背包标准 */
        /* 4. 遍历顺序：排列 先包后物 */
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i <= target; i++){
            for (int j = 0; j < nums.size(); j++){
                if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }


        /* 5. 举例验证 */
        // 1 2 3  target: 4
        // dp[0] 1
        // dp[1] 1
        // dp[2] 1 + 1
        // dp[3] 2 + 1 + 1
        // dp[4] 4 + 2 + 1
        return dp[target];

    }
};

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int& a : nums){
        cin >> a;
    }
    cout << Solution().combinationSum4(nums, target) << endl;
    return 0;
}