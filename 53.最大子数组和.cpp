#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int current_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            /* 记录过程中最大值 */
            if (current_sum > sum) {
                sum = current_sum;
            }
            /* 注意这两个要分开判断，否则会无法覆盖小于0的情况 */
            /* 如果小于0，就设置为0 */
            if (current_sum < 0) {
                current_sum = 0;
            }
        }
        return sum;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().maxSubArray(nums) << endl;
    return 0;
}