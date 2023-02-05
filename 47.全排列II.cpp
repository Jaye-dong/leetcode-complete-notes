#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool> &used){
        if(nums.size() == path.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true || (i > 0 && nums[i] == nums[i-1] && used[i-1] == false)){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }

};


int main(){
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    Solution solution;
    vector<vector<int>> res = solution.permuteUnique(nums);
    for(auto v : res){
        for(int a : v){
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}

