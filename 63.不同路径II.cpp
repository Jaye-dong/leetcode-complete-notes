#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));

        /* 1. ȷ��dp�±꺬�壺 dp[i][j]��ʾi, j�ж�����·�� */
        /* 2. ȷ�����ƹ�ʽ�� dp[i][j] = dp[i-1][j] + dp[i][j-1] */
        /* 3. ȷ����ʼ�� */
        for(int i = 0; i < obstacleGrid.size(); i++){
            if(obstacleGrid[i][0]){
                dp[i][0] = 0;
                break;
            }
            dp[i][0] = 1;
        }
        for(int j = 0; j < obstacleGrid[0].size(); j++){
            if(obstacleGrid[0][j]){
                dp[0][j] = 0;
                break;
            }
            dp[0][j] = 1;
        }

        /* 4. ȷ������˳�� */
        for(int i = 1; i < obstacleGrid.size(); i++){
            for(int j = 1; j < obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        /* 5. �����Ƶ� */
        // 1 1 1
        // 1 0 1
        // 1 1 2
        {
            for(auto v : dp){
                for(int a : v){
                    cout << a << " ";
                }
                cout << endl;
            }
        }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};


int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> obstacles(m, vector<int>(n, 0));
    obstacles[1][1] = 1;

    cout << Solution().uniquePathsWithObstacles(obstacles) << endl;
    return 0;
}