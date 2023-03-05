#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int fib(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        return fib(n-1) + fib(n-2);
    }
};


class Solution2 {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int dp[2];
        
        /* ȷ��dp�±꺬�� */
        /* dp[i]��ʾfibֵ */

        /* ȷ���Ƶ���ʽ */
        /* dp[i] = dp[i-1] + d[i-2]

        /* ȷ����ֵ */
        dp[0] = 0;
        dp[1] = 1;

        /* ȷ������˳�� */
        for(int i = 2; i <= n; i++){
            int sum = dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = sum;
        }

        /* �����Ƶ� */
        /* n = 2 
           dp[2] = 0 + 1 = 1;
        */
        return dp[1];
    }
};


class Solution3 {
public:
    int fib(int n){
        if (n <= 1) return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

int main(){
    int n = 0;
    cin >> n;
    cout << Solution().fib(n) << endl;
    return 0;
}