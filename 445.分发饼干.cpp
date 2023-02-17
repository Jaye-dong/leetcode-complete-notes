#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;
        /* 把最小的饼分给最小的孩子 */
        for(int i = 0; i < s.size(); i++){
            /* 如果最小的孩子能够被满足，被满足的孩子数+1 */
            if(index <= s.size() && g[index] <= s[i]){
                index++;
            }
            /* 否则，继续次小的饼分给这个孩子 */
            /* 小到最小的孩子都满足不了的饼其实是没有用的 */
        }
        return index;
    }
};



int main(){
    int n, m;
    cin >> n >> m;
    vector<int> g(n,0);
    vector<int> s(m, 0);
    for(int i = 0; i < n; i++){
        cin >> g[i];
    }
    for(int i = 0; i < m; i++){
        cin >> s[i];
    }
    Solution solution;
    cout << solution.findContentChildren(g, s) << endl;
    return 0;
}