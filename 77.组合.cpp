#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i <= n - (k - path.size()) + 1; i++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
};
int main(){
    int n, k;
    cin >> n >> k;
    Solution solution;
    vector<vector<int>> res = solution.combine(n, k);
    for(auto v : res){
        for(int a : v){
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}

