#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex){
        if(path.size() > 1){
            res.push_back(path);
        }
        unordered_set<int> uset;
        for(int i = startIndex; i < nums.size(); i++){
            if(uset.find(nums[i]) != uset.end() || (!path.empty() && nums[i] < path.back())){
                continue;
            }
            path.push_back(nums[i]);
            uset.insert(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
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
    vector<vector<int>> res = solution.findSubsequences(nums);
    for(auto v : res){
        for(int a : v){
            cout << a << " ";
        }
        cout << endl;
    }
    
    return 0;
}