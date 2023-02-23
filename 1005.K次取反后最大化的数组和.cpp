#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
    static bool cmp(const int a, const int b){
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        /* 第一步： 按绝对值排序 */
        sort(nums.begin(), nums.end(), cmp);
        /* 第二步： 遍历，把绝对值最大的那些负数反转 */
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
            if (k <= 0){
                break;
            }
            
        }
        /* 第三步： 如果k还有，判断是不是可以被2整除 */
        if (k % 2 != 0){
            nums[nums.size() - 1] = -nums[nums.size() - 1];
        }
        /* 第四步： 求和 */
        int sum = 0;
        for(auto a : nums){
            sum += a;
        }
        return sum;
    }
};


int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int k;
    cin >> k;
    cout << Solution().largestSumAfterKNegations(nums, k) << endl;
    return 0;
}