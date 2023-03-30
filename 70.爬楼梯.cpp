#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        vector<int> dp(n+1, 0);
        /* 1.确定dp下标含义dp[i]表示爬到第i阶有多少种方法 */

        /* 2. 确定状态转移方程 dp[i] = dp[i-1] + dp[i-2] */

        /* 3. 确定初始化值 */
        dp[1] = 1;
        dp[2] = 2;

        /* 4. 确定遍历顺序 从前往后 */
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        /* 5. 举例推导 */
        /* 3 ：  1 + 2 = 3 */

        return dp[n];
    }

    int climbStairs(int n, int method2) {
        /* 完全背包解法 */
        /* 1. dp[i]：爬到第i阶有多少种方法 */
        /* 2. dp[i] += dp[i - nums[j]] */
        /* 3. dp[0] = 1 */
        /* 4. 排列，先包后物 */
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int m = 2;
        for(int i = 0; i <= n; i++) {
            for (int j = 1; j <= 2; j++) {
                if(i >= j){
                    dp[i] += dp[i - j];
                }
            }
        }
        /* 5. 没时间，先不验啦 */
        return dp[n];
    }
};


int main(){
    int n;
    cin >> n;
    cout << Solution().climbStairs(n) << endl;
    cout << Solution().climbStairs(n,0) << endl;
    return 0;
}