#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        /* 1. ȷ��dp�±꺬�壺dp[i]��ʾ��1-i������ͬ�Ķ������ж����� */
        /* 2. ȷ�����ƹ�ʽ�� dp[i] += dp[i-j]*dp[j-1] */
        /* 3. ȷ����ʼֵ */
        dp[0] = 1;
        /* 4. ȷ������˳�� */
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i] += dp[i - j] * dp[j - 1];
            }
        }
        /* 5. �����Ƶ� */
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