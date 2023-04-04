#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    // 需要加的时候可以用这个因为INT_MAX + 1会溢出
    static int inf;
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        // 最终要满足能够合成一个 n需要满足1加上k-1个堆的倍数，因为每一次合并都会减少k - 1个堆
        if ((n - 1) % (k - 1) != 0){
            return -1;
        }
        /* 1. dp[i][j][t]表示合并为t堆，所需要的最小成本 */
        /* 2. t == 1时 dp[i][j][t] = dp[i][j][k] + sum[i][j]，也就是，需要这i-j先合成k堆的成本，在加上本次合并的成本
        /*    t > 1时 dp[i][j][t] = min(dp[i][j][t], dp[i][p][1] + dp[p + 1][j][t - 1]) 
                    可以分为之间合成t堆的成本和拆分成1和t-1堆的成本， i <= p <= j */ 
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, inf)));
        // 用于记录0-n-1的和，便于计算i~j的和，求差即可
        vector<int> sum(n, 0);
        /* 3. 初值dp[i][i][1] = 0, 合并为一个的开销为0，因为就在那，不需要合并 */
        // s和 sum[i] = s, 求sum的小技巧
        for(int i = 0, s = 0; i < n; i++){
            dp[i][i][1] = 0;
            s += stones[i];
            sum[i] = s;
        }
        /* 4. 长度遍历，l遍历，t遍历，p遍历 */
        for(int len = 2; len <= n; len++) {
            for(int l = 0; l < n && l + len - 1 < n; l++){
                int r = l + len - 1;
                /* 分别2堆和k堆 */
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