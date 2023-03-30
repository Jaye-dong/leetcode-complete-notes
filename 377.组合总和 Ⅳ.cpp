#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /* 1. dp[i] : Ŀ���Ϊi����ϸ�����˳��ͬ��Ϊ��ͬ��ϣ�ʵ������������ */
        /* 2. dp[i] += dp[i - nums[j]]; ��װ�������ж�����װ���ı�׼���ƹ�ʽ */
        /* 3. dp[0] = 1; ��ȫ������׼ */
        /* 4. ����˳������ �Ȱ����� */
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i <= target; i++){
            for (int j = 0; j < nums.size(); j++){
                if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }


        /* 5. ������֤ */
        // 1 2 3  target: 4
        // dp[0] 1
        // dp[1] 1
        // dp[2] 1 + 1
        // dp[3] 2 + 1 + 1
        // dp[4] 4 + 2 + 1
        return dp[target];

    }
};

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int& a : nums){
        cin >> a;
    }
    cout << Solution().combinationSum4(nums, target) << endl;
    return 0;
}