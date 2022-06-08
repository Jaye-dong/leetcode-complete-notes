#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int j = 0;
        int res = 0;
        unordered_map<int, int> basket;
        int count = 0;

        for (j = 0; j < (int)fruits.size();) {
            /* ������������Ϊ0 */
            if(basket[fruits[j]] == 0){
                count++;
            }
            basket[fruits[j]]++;
            /* ������೬��2 */
            while(count > 2){
                /* ����ƶ�������ֻʣ��һ�� */
                if(basket[fruits[i]] == 1){
                    /* ����  - 1 */
                    count--;
                }
                /* ÿ�ƶ�һ�Σ��Ѹ���������һ */
                basket[fruits[i]]--;
                i += 1;
            }
            /* ���������������ֵ */
            res = max(res, j - i + 1);
            j += 1;
        }
        return res;
    }
};

int main(){
    Solution solution;
    // vector<int> a = {2, 2, 3, 4, 4};
    vector<int> a{3,3,3,1,2,1,1,2,3,3,4};
    int res = solution.totalFruit(a);
    cout << res << endl;
    return 0;
}