#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    bool isValid(int row, int col, int n){
        /* 检查列 */
        for(int i = 0; i < row; i++){
            if(path[i][col] == 'Q') return false;
        }

        /* 检查45° */
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(path[i][j] == 'Q') return false;
        }

        /* 检查135° */
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(path[i][j] == 'Q') return false;
        }
        return true;

    }
    void backtracking(int n, int row){
        if(row == n){
            result.push_back(path);
            return;
        }
        for(int i = 0; i < n; i++){
            if(!isValid(row, i, n)){
                continue;
            }
            path[row][i] = 'Q';
            backtracking(n, row + 1);
            path[row][i] = '.';

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        path.resize(n);
        for(int i = 0; i < n; i++){
            path[i] = string(n,'.');
        }
        backtracking(n, 0);
        return result;
    }
};

int main(){
    int n;
    cin >> n;
    Solution solution;
    vector<vector<string>> res = solution.solveNQueens(n);
    for(auto v : res){
        for( const string& s : v){
            cout << s << " ";
            cout << endl;
        }
        cout << endl;
        
    }
    return 0;
}