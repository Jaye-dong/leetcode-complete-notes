#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums, const string method = "tx") {
        if(nums.size() == 0) return 0;
        int result = nums[0];
        if(method == "tx"){
            int count = 0;
            for(int i = 0; i < nums.size(); i++){
                count += nums[i];
                if(count > result){
                    result = count;
                }
                if(count < 0){
                    count = 0;
                }
            }
        }else if(method == "dp"){
            int pre = nums[0];
            for(int i = 1; i < nums.size(); i++){
                pre = max(pre + nums[i], nums[i]);
                result = max(pre, result);
            }
        }

        return result;
    }

};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution solution;
    cout << solution.maxSubArray(nums, "dp") << endl;
    return 0;
}