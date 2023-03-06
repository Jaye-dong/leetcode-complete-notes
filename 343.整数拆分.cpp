#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        /* 1. 确定dp下标含义： dp[i]表示数字i拆分后的最大乘积 */
        /* 2. 确定递推公式 */
        // dp[i] = max(dp[i], max(j * (i- j), j * dp[i-j]))
        /* 3. 确定初始化 */
        dp[2] = 1;
        /* 4. 确定遍历顺序 */
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i - 1; j++){
                dp[i] = max(dp[i], max(j * (i- j), j * dp[i-j]));
            }
        }
        /* 5. 举例推导 */
        // 4
        // i =  3 :  0, 1*2 1*1  2 
        // i =  4 :  1*3, 1*2 3  3, 2*2 2*1
        // 4
        return dp[n];

    }
};


int main(){
    int n;
    cin >> n;
    cout << Solution().integerBreak(n) << endl;
    return 0;
}