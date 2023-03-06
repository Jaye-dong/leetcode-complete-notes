#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        /* 1. 确定dp下标含义： dp[i][j]表示到i, j有多少种走法 */
        
        /* 2. 确定递推公式 dp[i][j] = dp[i-1][j] + dp[i][j-1] */

        /* 3. 确定初始化 */
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; j++){
            dp[0][j] = 1;
        }

        /* 4. 确定遍历顺序 */
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        /* 5. 举例推导 */
        // 1 1
        // 1 ？  1 + 1 = 2
        return dp[m-1][n-1];
    }
};

int main(){
    int m, n;
    cin >> m >> n;
    cout << Solution().uniquePaths(m, n) << endl;
    return 0;
}