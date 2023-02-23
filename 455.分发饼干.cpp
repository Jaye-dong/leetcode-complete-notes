#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) const {
        /* 饼干和小孩需求按照从小到大进行排序*/
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        /* 用于存放结果和遍历小孩 */
        int index = 0;
        /* 优先遍历饼干，因为饼干不重要，小的饼干（无法满足任何小孩的）可以抛弃 */
        for(int i = 0; i < s.size(); i++){
            /* 永远记得检查边界 */
            if(index < g.size() && s[i] >= g[index]){
                index++;
            }
        }
        return index;
    }
};


int main(){
    vector<int> g{1, 2, 3};
    vector<int> s{1, 1};
    Solution solu;

    cout << solu.findContentChildren(g, s) << endl;
    return 0;
}