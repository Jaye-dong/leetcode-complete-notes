#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // ��Ҫ�ӵ�ʱ������������ΪINT_MAX + 1�����
    static int inf;
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        // ����Ҫ�����ܹ��ϳ�һ�� n��Ҫ����1����k-1���ѵı�������Ϊÿһ�κϲ��������k - 1����
        if ((n - 1) % (k - 1) != 0){
            return -1;
        }
        /* 1. dp[i][j][t]��ʾ�ϲ�Ϊt�ѣ�����Ҫ����С�ɱ� */
        /* 2. t == 1ʱ dp[i][j][t] = dp[i][j][k] + sum[i][j]��Ҳ���ǣ���Ҫ��i-j�Ⱥϳ�k�ѵĳɱ����ڼ��ϱ��κϲ��ĳɱ�
        /*    t > 1ʱ dp[i][j][t] = min(dp[i][j][t], dp[i][p][1] + dp[p + 1][j][t - 1]) 
                    ���Է�Ϊ֮��ϳ�t�ѵĳɱ��Ͳ�ֳ�1��t-1�ѵĳɱ��� i <= p <= j */ 
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, inf)));
        // ���ڼ�¼0-n-1�ĺͣ����ڼ���i~j�ĺͣ�����
        vector<int> sum(n, 0);
        /* 3. ��ֵdp[i][i][1] = 0, �ϲ�Ϊһ���Ŀ���Ϊ0����Ϊ�����ǣ�����Ҫ�ϲ� */
        // s�� sum[i] = s, ��sum��С����
        for(int i = 0, s = 0; i < n; i++){
            dp[i][i][1] = 0;
            s += stones[i];
            sum[i] = s;
        }
        /* 4. ���ȱ�����l������t������p���� */
        for(int len = 2; len <= n; len++) {
            for(int l = 0; l < n && l + len - 1 < n; l++){
                int r = l + len - 1;
                /* �ֱ�2�Ѻ�k�� */
                for(int t = 2; t <= k; t++){
                   for(int p = l; p < r; p += k - 1) {
                        dp[l][r][t] = min(dp[l][r][t], dp[l][p][1] + dp[p + 1][r][t - 1]);
                   }
                }
                dp[l][r][1] = min(dp[l][r][1], dp[l][r][k] + sum[r] - (l == 0? 0 : sum[l - 1]));
            }
        }
        return dp[0][n - 1][1];
        
    }
};

int Solution::inf = 0x3f3f3f3f;




int main(){
    int n, k;
    cin >> n >> k;
    vector<int> stones(n);
    for(int i = 0; i < n; i++){
        cin >> stones[i];
    }
    cout << Solution().mergeStones(stones, k) << endl;
    return 0;
}