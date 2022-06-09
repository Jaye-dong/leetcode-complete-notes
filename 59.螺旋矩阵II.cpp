#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        /* ѭ����Ȧ�� */
        int loop = n / 2;

        /* ������� */
        vector<vector<int> > res(n, vector<int>(n, 0));

        /* ��ʼλ�� */
        int startx = 0;
        int starty = 0;
        int i, j;

        /* ÿһ�����ӵĸ�ֵ */
        int count = 1;

        /* ����ÿһȦ���߽�ĳ��� */
        int offset = 1;

        /* ������м�λ�� */
        int mid = n / 2;

        while(loop--){
            i = startx;
            j = starty;

            /* �� */
            while(j < n + starty - offset){
                res[i][j] = count++;
                j++;
            }

            /* �� */
            while(i < n + startx - offset){
                res[i][j] = count++;
                i++;
            }

            /* �� */
            while(j > starty){
                res[i][j] = count++;
                j--;
            }

            /* �� */
            while(i > startx){
                res[i][j] = count++;
                i--;
            }

            /* ��ʼλ�ø��� */
            startx++;
            starty++;

            /* ���߽�ľ������ */
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