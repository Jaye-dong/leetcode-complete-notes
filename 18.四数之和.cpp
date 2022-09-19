#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size(); k++){
            if(nums[k] > target && nums[k] >= 0){
                break;
            }
            if(k > 0 && nums[k] == nums[k-1]){
                continue;    
            }
            for(int i = k + 1; i < nums.size(); i++){
                if( nums[i] + nums[k] > target && nums[i] + nums[k]>= 0){
                    break;
                }
                if( i > k+1 && nums[i] == nums[i-1]){
                    continue;
                }

                int left = i + 1;
                int right = nums.size() - 1;
                while(left < right){
                    if((long)nums[k] + nums[i] + nums[left] + nums[right] == target){
                    res.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                    while(left < right && nums[right] == nums[--right]);
                    while(left < right && nums[left] == nums[++left]);
                    }else if((long)nums[k] + nums[i] + nums[left] + nums[right] < target){
                        left++;
                    }else{
                        right--;
                    }
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
    for(auto a: nums){
        cout << a << " ";
    }
    cout << endl;
    int target;
    cin >> target;
    Solution solution;
    vector<vector<int>> res = solution.fourSum(nums, target);
    for(auto a : res){
        for(auto b: a){
            cout << b << " ";
        }
        cout << endl;
    }
    
    return 0;
}