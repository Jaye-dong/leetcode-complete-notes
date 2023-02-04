#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &candidates, int target, int sum, int startIndex){
        if(sum == target){
            res.push_back(path);
            return;
        }
        for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++){
            if(i > startIndex && candidates[i] == candidates[i-1]){
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return res;
    }
};

int main(){

    int n;
    cin >> n;
    vector<int> canditates(n, 0);
    for(int i = 0; i < n; i++){
        cin >> canditates[i];
    }
    Solution solution;
    int target;
    cin >> target;
    vector<vector<int>> res = solution.combinationSum2(canditates, target);

    for(auto v : res){
        for(int a : v){
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}