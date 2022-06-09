#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        /* 循环的圈数 */
        int loop = n / 2;

        /* 结果矩阵 */
        vector<vector<int> > res(n, vector<int>(n, 0));

        /* 起始位置 */
        int startx = 0;
        int starty = 0;
        int i, j;

        /* 每一个格子的赋值 */
        int count = 1;

        /* 控制每一圈到边界的长度 */
        int offset = 1;

        /* 矩阵的中间位置 */
        int mid = n / 2;

        while(loop--){
            i = startx;
            j = starty;

            /* → */
            while(j < n + starty - offset){
                res[i][j] = count++;
                j++;
            }

            /* ↓ */
            while(i < n + startx - offset){
                res[i][j] = count++;
                i++;
            }

            /* ← */
            while(j > starty){
                res[i][j] = count++;
                j--;
            }

            /* ↑ */
            while(i > startx){
                res[i][j] = count++;
                i--;
            }

            /* 起始位置更新 */
            startx++;
            starty++;

            /* 到边界的距离更新 */
            offset += 2;

        }

        if(n % 2){
            res[mid][mid] = count;
        }

        return res;
    }
};

int main(){

    Solution solution;
    int n = 5;
    vector<vector<int>> res = solution.generateMatrix(n);
    for(int i = 0; i < (int)res.size(); i++){
        for(int j = 0; j < (int)res[0].size(); j++){
            cout << res[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}