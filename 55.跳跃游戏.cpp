#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        for (int i = 0; i <= cover; i++) {
            cover = max(cover, nums[i] + i);
            if (cover >= nums.size() - 1){
                return true;
            }
        }
        return false;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << Solution().canJump(nums) << endl;
    return 0;
}