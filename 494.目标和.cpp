#include <iostream>
#include <vector>


using namespace std;
 
 
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0;
        for(int a : nums){
            sum += a;
        }
        /* left + right = sum */
        /* left - right = target */
        /* left = (sum + target) / 2*/
        if(abs(target) > sum) {
            return 0;
        }
        if((sum + target) % 2 == 1){
            return 0;
        }
        
        int bagSize = (sum + target) / 2;
        /* 1. dp[j] 表示装满大小j的包有多少种方法 */
        /* 2. dp[j] += dp[j - nums[i]] */
        /* 3. 初始化 dp[0] = 1 */
        /* 4. 01背包遍历顺序 */
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = bagSize; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};


int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cout << Solution().findTargetSumWays(nums, k) << endl;

    return 0;
}
