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
            /* 如果该种类个数为0 */
            if(basket[fruits[j]] == 0){
                count++;
            }
            basket[fruits[j]]++;
            /* 如果种类超过2 */
            while(count > 2){
                /* 如果移动到该类只剩下一个 */
                if(basket[fruits[i]] == 1){
                    /* 种类  - 1 */
                    count--;
                }
                /* 每移动一次，把该类数量减一 */
                basket[fruits[i]]--;
                i += 1;
            }
            /* 求满足条件的最大值 */
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