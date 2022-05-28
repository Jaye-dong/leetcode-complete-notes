#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> merge(vector<int> a, vector<int> b){
        return vector<int>{max(a[0], b[0]), min(a[1], b[1])};
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int> > res;
        /* ���һ��ListΪ���򷵻ؿ� */
        if(firstList.size() == 0) return res; 
        if(secondList.size() == 0) return res; 
        
        /* ����index����ʾ����List��ǰ�Ƚϵ�ֵ */
        vector<int> index(2, 0);
        /* ѭ����ʼ���������һ��index����size�˾��˳� */
        while(index[0] < (int)firstList.size() && index[1] < (int)secondList.size()){
            if(!(firstList[index[0]][0] > secondList[index[1]][1] ||  firstList[index[0]][1] < secondList[index[1]][0])){
                /* ���Ԫ�� */
                res.push_back(merge(firstList[index[0]], secondList[index[1]]));;
            }
            /* ���Ҷ˵��С�������indexֵ�����Լ�1 */
            if(secondList[index[1]][1] > firstList[index[0]][1]){
                index[0]++;
            }else if(secondList[index[1]][1] < firstList[index[0]][1]){
                index[1]++;
            }else{
                index[0]++;
                index[1]++;
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int> > firstL = {{0,2},{5,10}, {13,23},{24,25} };
    vector<vector<int> > secondL = {{1,5},{8,12},{15,24},{25,26} };
    // vector<vector<int> > firstL = {{1, 7}};
    // vector<vector<int> > secondL = {{3,10}};
    // vector<vector<int> > firstL = {{8,15} };
    // vector<vector<int> > secondL = {{2,6},{8,10},{12,20} };
    // vector<vector<int> > firstL = {{4,11} };
    // vector<vector<int> > secondL = {{1,2},{8,11},{12,13}, {14,15}, {17,19} };
    // vector<vector<int> > firstL = {{1,8}, {16,20} };
    // vector<vector<int> > secondL = {{2,11},{12,13} };
    Solution solution;
    vector<vector<int> > res = solution.intervalIntersection(firstL, secondL);
    for(int i = 0; i < (int)res.size(); i++){
        cout << res[i][0] << ", " << res[i][1] << endl;
    }
    return 0;
}