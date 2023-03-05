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
};


int main(){
    int n;
    cin >> n;
    cout << Solution().climbStairs(n) << endl;
    return 0;
}