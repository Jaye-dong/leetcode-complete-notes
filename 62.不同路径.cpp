#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        /* 1. ȷ��dp�±꺬�壺 dp[i][j]��ʾ��i, j�ж������߷� */
        
        /* 2. ȷ�����ƹ�ʽ dp[i][j] = dp[i-1][j] + dp[i][j-1] */

        /* 3. ȷ����ʼ�� */
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; j++){
            dp[0][j] = 1;
        }

        /* 4. ȷ������˳�� */
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        /* 5. �����Ƶ� */
        // 1 1
        // 1 ��  1 + 1 = 2
        return dp[m-1][n-1];
    }
};

int main(){
    int m, n;
    cin >> m >> n;
    cout << Solution().uniquePaths(m, n) << endl;
    return 0;
}