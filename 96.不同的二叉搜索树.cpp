#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        /* 1. 确定dp下标含义：dp[i]表示从1-i互不相同的二叉树有多少种 */
        /* 2. 确定递推公式： dp[i] += dp[i-j]*dp[j-1] */
        /* 3. 确定初始值 */
        dp[0] = 1;
        /* 4. 确定遍历顺序 */
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i] += dp[i - j] * dp[j - 1];
            }
        }
        /* 5. 举例推导 */
        // 1 dp[1] += dp[0]*dp[0] = 1
        // 2 dp[2] += dp[1]*dp[0] + dp[0]*dp[1] = 1 + 1 = 2
        // 3 dp[3] += dp[2]*dp[0] + dp[1]*dp[1] + dp[0]*dp[2] = 2 + 1 + 2 = 5
        return dp[n];
    }
};


int main() {
    int n;
    cin >> n;
    cout << Solution().numTrees(n) << endl;
    return 0;
}