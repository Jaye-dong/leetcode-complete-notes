#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution{
public:
    vector<int> path;
    vector<vector<int>> res;
    int sumPath(vector<int> &vec){
        int sum = 0;
        for(auto a : vec){
            sum += a;
        }
        return sum;
    }
    int accumualte(int k){
        int accum = 0;
        for(int i = 1; i < k; i++){
            accum += i;
        }
        return accum;
    }
    void backtracking(int k, int n, int startIndex){
        if(path.size() == k ){
            if(sumPath(path) == n) res.push_back(path);
            return;
        }

        for(int i = startIndex; i <= 9 - (k - path.size()) + 1; i++){
            path.push_back(i);
            backtracking(k, n, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // res.push_back(path);
        backtracking(k, n, 1);
        return res;
    }
};

int main(){
    int k, n;
    cin >> k >> n;
    Solution solution;
    vector<vector<int>> res = solution.combinationSum3(k, n);
    for(auto v : res){
        for(int a : v){
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}