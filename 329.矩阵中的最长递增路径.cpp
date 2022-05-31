#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int> > &memo){
        
        /* 判断是否到达边界 */
        if(x < 0 || x >= (int)matrix.size() || y < 0 || y >= (int)matrix[0].size()){
            return 0;
        }
        /* 如果已经计算过了，就直接返回记录的结果 */
        if(memo[x][y] != 0){
            return memo[x][y] + 1;
        }
        int maxpath = 0;
        
        if(x + 1 < (int)matrix.size() && matrix[x + 1][y] > matrix[x][y]) maxpath = max(dfs(matrix, x + 1, y, memo), maxpath);
        if(x - 1 >= 0 && matrix[x - 1][y] > matrix[x][y]) maxpath = max(dfs(matrix, x - 1, y, memo), maxpath);
        if(y + 1 < (int)matrix[0].size() && matrix[x][y + 1] > matrix[x][y]) maxpath = max(dfs(matrix, x, y + 1, memo), maxpath);
        if(y - 1 >= 0 && matrix[x][y - 1] > matrix[x][y]) maxpath = max(dfs(matrix, x, y - 1, memo), maxpath);
        /* 记住结果 */
        memo[x][y] = maxpath;
        return maxpath + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        vector<vector<int> > memo(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i = 0; i < (int)matrix.size(); i++){
            for(int j = 0; j < (int)matrix[0].size(); j++){
                res = max(dfs(matrix, i, j, memo), res);
            }
        }
        return res;
    }
};

int main(){
    // vector<vector<int> > a = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    // vector<vector<int> > a = {{1, 2, 3}, {6, 5, 4}, {7, 8, 9}};
    // vector<vector<int> > a;
    
    // vector<vector<int> > a = {{2,1}};

    vector<vector<int> > a ={{0,1,2,3,4,5,6,7,8,9},{19,18,17,16,15,14,13,12,11,10},{20,21,22,23,24,25,26,27,28,29},{39,38,37,36,35,34,33,32,31,30},{40,41,42,43,44,45,46,47,48,49},{59,58,57,56,55,54,53,52,51,50},{60,61,62,63,64,65,66,67,68,69},{79,78,77,76,75,74,73,72,71,70},{80,81,82,83,84,85,86,87,88,89},{99,98,97,96,95,94,93,92,91,90},{100,101,102,103,104,105,106,107,108,109},{119,118,117,116,115,114,113,112,111,110},{120,121,122,123,124,125,126,127,128,129},{139,138,137,136,135,134,133,132,131,130},{0,0,0,0,0,0,0,0,0,0}};
    Solution solution;
    cout << solution.longestIncreasingPath(a) << endl;

    return 0;
}