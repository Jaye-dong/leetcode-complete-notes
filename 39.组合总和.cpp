#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum  = 0;
    void backtracking(vector<int> &candidates, int target, int startIndex){
        if(sum > target){
            return;
        }
        if(sum == target){
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> candidates(n, 0);
    for(int i = 0; i < n; i++){
        cin >> candidates[i];
    }
    int target;
    cin >> target;
    Solution solution;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    for(auto v : res){
        for(int a : v){
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}