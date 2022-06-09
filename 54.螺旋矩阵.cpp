#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m;
        if(n > 0) {
            m = matrix[0].size();
        }else{
            return vector<int>{0};
        }
        
        /* Ȧ�� */
        int loop = min(matrix.size(), matrix[0].size()) / 2;

        /* ��� */
        vector<int> res(n * m, 0);

        /* �м�ֵ */
        int midx = n / 2;
        int midy = m / 2;

        /* ��ʼ������ֵ */
        int startx = 0;
        int starty = 0;
        int i, j;

        /* �߽���ֵ */
        int offset = 1;

        /* ���index */
        int index = 0;
        while(loop--){
            i = startx;
            j = starty;

            /* �� */
            while(j < m + starty - offset){
                res[index++] = matrix[i][j];
                j++;
            }

            /* �� */
            while(i < n + startx - offset){
                res[index++] = matrix[i][j];
                i++;
            }

            /* �� */
            while(j > starty){
                res[index++] = matrix[i][j];
                j--;
            }

            /* �� */
            while(i > startx){
                res[index++] = matrix[i][j];
                i--;
            }

            /* ����offset */
            offset += 2;

            /* ������ʼ��ַ */
            startx++;
            starty++;
            
        }
        /* ����Ƿ����������ֻ��һ���ն� */
        if(n*m % 2 && n == m){
            res[index] = matrix[midx][midy];
        }
        /* ��������������Ͽն� */
        if(index < (int)res.size() - 1 && n != m){
            int holo = abs(n-m) + 1;
            if(m > n){
                for(int i = 0; i < holo; i++){
                    res[index++] = matrix[startx][starty++];
                }
            }
            if(m < n){
                for(int i = 0; i < holo; i++){
                    res[index++] = matrix[startx++][starty];
                }
            }
        }
        
        return res;
        
    }
};

int main(){

    Solution solution;

//  vector<vector<int>> res{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//  vector<vector<int>> res{{3},{2}};
    // vector<vector<int>> res{{6,9,7}};
    vector<vector<int>> res{{2,5},{8,4},{0,-1}};
    for(int i = 0; i < (int)res.size(); i++){
        for(int j = 0; j < (int)res[0].size(); j++){
            cout << res[i][j] << ", ";
        }
        cout << endl;
    }
    vector<int> resline = solution.spiralOrder(res);
    for(int i = 0; i < (int)resline.size(); i++){
        cout << resline[i] << ", ";
    }
    return 0;
}