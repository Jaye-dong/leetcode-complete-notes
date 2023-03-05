#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, 0);
        /* 1. 确定dp下标含义： dp[i]表示到第i阶的最小代价 */
        
        /* 2. 确认状态转移方程： dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]) */

        /* 3. 确认初始化值 */
        dp[0] = 0;
        dp[1] = 0;

        /* 4. 确认遍历顺序 */
        for(int i = 2; i <= cost.size(); i++){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }

        /* 5. 举例：
          cost:  1 100 1 1 1 100 1 1 100 1
            dp： 0  0  1 2 2 3   3 4  4  5 6
        */

       return dp[cost.size()];

    }
};

int main(){
    int n;
    cin >> n;
    vector<int> cost(n);
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    cout << Solution().minCostClimbingStairs(cost) << endl;
    return 0;
}