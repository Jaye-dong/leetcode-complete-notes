#include <iostream>
#include <vector>
#include <climits>

using namespace std;
class Solution {
public:
    /* 返回值定义为int，保存递归返回结果为上一层递归所用 */
    int dfs(vector<vector<int>>& grid, int i, int j){
        if( i < 0 || i >= (int)grid.size() || j <0 || j >= (int)grid[0].size() || grid[i][j] != 1){
            return 0;
        }
        /* 递归过的地方置为0，防止反复遍历陷入死循环 */
        grid[i][j] = 0;
        /* 本身是1，加上四个方向的1 */
        int ans = 1;
        /* 分别对四个方向进行深度优先遍历 */
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
                /* 对grid中每一个点进行遍历，得出该点所在区域面积，每次遍历实际上会将一个“岛屿”置为0 */
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