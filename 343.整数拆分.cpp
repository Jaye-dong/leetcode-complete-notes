#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        /* 1. ȷ��dp�±꺬�壺 dp[i]��ʾ����i��ֺ�����˻� */
        /* 2. ȷ�����ƹ�ʽ */
        // dp[i] = max(dp[i], max(j * (i- j), j * dp[i-j]))
        /* 3. ȷ����ʼ�� */
        dp[2] = 1;
        /* 4. ȷ������˳�� */
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i - 1; j++){
                dp[i] = max(dp[i], max(j * (i- j), j * dp[i-j]));
            }
        }
        /* 5. �����Ƶ� */
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