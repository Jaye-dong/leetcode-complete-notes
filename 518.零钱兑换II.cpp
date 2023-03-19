#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /* 1. dp[j]��amountΪj������ж����� */
        /* 2. dp[j] += dp[j - coins[i]] */
        /* 3. dp[0] = 1 */
        /* 4. ��ȫ������ϱ���˳�������� */
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

int main(){
    int a, n;
    cin >> a >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    
    cout << Solution().change(a, coins) << endl;
    return 0;
}