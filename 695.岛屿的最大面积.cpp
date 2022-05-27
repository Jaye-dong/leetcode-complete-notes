#include <iostream>
#include <vector>
#include <climits>

using namespace std;
class Solution {
public:
    /* ����ֵ����Ϊint������ݹ鷵�ؽ��Ϊ��һ��ݹ����� */
    int dfs(vector<vector<int>>& grid, int i, int j){
        if( i < 0 || i >= (int)grid.size() || j <0 || j >= (int)grid[0].size() || grid[i][j] != 1){
            return 0;
        }
        /* �ݹ���ĵط���Ϊ0����ֹ��������������ѭ�� */
        grid[i][j] = 0;
        /* ������1�������ĸ������1 */
        int ans = 1;
        /* �ֱ���ĸ��������������ȱ��� */
        ans += dfs(grid, i - 1, j);
        ans += dfs(grid, i, j - 1);
        ans += dfs(grid, i + 1, j);
        ans += dfs(grid, i, j + 1);

        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxS = INT_MIN;
        for(int i = 0; i < (int)grid.size(); i++){
            for(int j = 0; j < (int)grid[0].size(); j++){
                /* ��grid��ÿһ������б������ó��õ��������������ÿ�α���ʵ���ϻὫһ�������족��Ϊ0 */
                maxS = max(dfs(grid, i, j), maxS);
            }
        }
        
        return maxS;
    }
};

int main(){
    vector<vector<int> > grid = {
                                {0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0},
    };
    Solution solution;
    int res = solution.maxAreaOfIsland(grid);
    cout << res << endl;
    
    return 0;
}