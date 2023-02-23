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
        /* ��һ���� ������ֵ���� */
        sort(nums.begin(), nums.end(), cmp);
        /* �ڶ����� �������Ѿ���ֵ������Щ������ת */
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
            if (k <= 0){
                break;
            }
            
        }
        /* �������� ���k���У��ж��ǲ��ǿ��Ա�2���� */
        if (k % 2 != 0){
            nums[nums.size() - 1] = -nums[nums.size() - 1];
        }
        /* ���Ĳ��� ��� */
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