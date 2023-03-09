#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /* 确定四点 */
        // 1. 背包的体积是sum/2
        // 2. 背包放入的物品是数组的值，重量也是数组的值
        // 3. 背包如果装满，说明找到了sum/2的子集
        // 4. 背包中每一个元素不可重复装入
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        /* 如果sum是奇数，不可能能够分成两个元素和相等的子集 */
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        /* 开始01背包*/
        vector<int> dp(target + 1, 0);
        for(int i = 0; i < nums.size(); i++){//遍历物品
            for(int j = target; j >= nums[i]; j--) {//遍历背包，比当前物体小的背包不用遍历
                dp[j] = max(dp[j], dp[j- nums[i]] + nums[i]);
            }
        }
        
        if (dp[target] == target) return true;
        return false;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << Solution().canPartition(nums) << endl;
    return 0;
}