#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        vector<int> dp(n+1, 0);
        /* 1.ȷ��dp�±꺬��dp[i]��ʾ������i���ж����ַ��� */

        /* 2. ȷ��״̬ת�Ʒ��� dp[i] = dp[i-1] + dp[i-2] */

        /* 3. ȷ����ʼ��ֵ */
        dp[1] = 1;
        dp[2] = 2;

        /* 4. ȷ������˳�� ��ǰ���� */
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        /* 5. �����Ƶ� */
        /* 3 ��  1 + 2 = 3 */

        return dp[n];
    }

    int climbStairs(int n, int method2) {
        /* ��ȫ�����ⷨ */
        /* 1. dp[i]��������i���ж����ַ��� */
        /* 2. dp[i] += dp[i - nums[j]] */
        /* 3. dp[0] = 1 */
        /* 4. ���У��Ȱ����� */
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
        /* 5. ûʱ�䣬�Ȳ����� */
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