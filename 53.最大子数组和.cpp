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
            /* ��¼���������ֵ */
            if (current_sum > sum) {
                sum = current_sum;
            }
            /* ע��������Ҫ�ֿ��жϣ�������޷�����С��0����� */
            /* ���С��0��������Ϊ0 */
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