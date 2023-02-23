#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int search(vector<int>& nums, int cur){
        int index = 0;
        int maxVal = 0;
        for(int i = 1; i + cur < nums.size() && i <= nums[cur]; i++){
            if(i + cur >= nums.size() - 1){
                return nums.size() - 1;
            }
            if(nums[i + cur] + i >= maxVal){
                maxVal = nums[i + cur] + i;
                index = i;
            }
        }
        return index + cur;
    }
    int jump(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i = search(nums, i)){
            if(i >= nums.size() - 1){
                break;
            }
            count++;
        }
        return count;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().jump(nums) << endl;
    return 0;
}