#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex) {
        res.push_back(path);
        for(int i = startIndex; i < nums.size(); i++){
            if(i > startIndex && nums[i] == nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
    vector<vector<int>> res = solution.subsetsWithDup(nums);
    for(auto v : res){
        for(int a : v){
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}