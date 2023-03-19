#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        /* 1. dp[i][j] 表示i个0和j个1最大的大小 */
        /* 2. dp[i][j] = max(dp[i-numZero][j-numOne] + 1, dp[i][j]) */
        /* 3. 初始化为0即可 */
        /* 4. 01 背包遍历顺序 */
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(string str : strs){
            int numZero = 0, numOne = 0;
            for(char c : str){
                if (c == '0') numZero++;
                else numOne++;
            }
            for(int i = m; i >= numZero; i--){
                for(int j = n; j >= numOne; j--){
                    dp[i][j] = max(dp[i][j], dp[i - numZero][j - numOne] + 1);
                }
            }
        }
        return dp[m][n];
    }
};


int main(){
    int N, m, n;
    cin >> N >> m >> n;
    vector<string> strs(N);
    for(int i = 0; i < N; i++){
        cin >> strs[i];
    }
    cout << Solution().findMaxForm(strs, m, n) << endl;
    return 0;
}