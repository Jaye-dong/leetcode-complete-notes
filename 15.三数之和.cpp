#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < (int)nums.size(); i++){
            if(nums[i] > 0){
                return res;
            }
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] == 0){
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(left<right && nums[left] == nums[++left]);
                    while(left<right && nums[right] == nums[--right]);
                }else if(nums[i] + nums[left] + nums[right] > 0){
                    --right;
                }else{
                    ++left;
                }
            }
        }

        return res;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution solution;
    vector<vector<int>> res = solution.threeSum(nums);
    for(auto r : res){
        for(auto j: r){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}