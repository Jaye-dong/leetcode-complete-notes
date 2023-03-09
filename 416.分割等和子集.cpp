#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /* ȷ���ĵ� */
        // 1. �����������sum/2
        // 2. �����������Ʒ�������ֵ������Ҳ�������ֵ
        // 3. �������װ����˵���ҵ���sum/2���Ӽ�
        // 4. ������ÿһ��Ԫ�ز����ظ�װ��
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        /* ���sum���������������ܹ��ֳ�����Ԫ�غ���ȵ��Ӽ� */
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        /* ��ʼ01����*/
        vector<int> dp(target + 1, 0);
        for(int i = 0; i < nums.size(); i++){//������Ʒ
            for(int j = target; j >= nums[i]; j--) {//�����������ȵ�ǰ����С�ı������ñ���
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