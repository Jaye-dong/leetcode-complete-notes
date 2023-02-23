#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        /* ���С�ڵ���1��ʾ���г���ֻ����ô�� */
        if (nums.size() <= 1){
            return nums.size();
        }
        /* ����������������֮��Ĳ�ֵ */
        int prediff = 0;
        int curdiff = 0;
        /* ��ֵ��1����ΪֻҪ��һ�����У�һ�����ٳ���Ϊ 2 */
        int count = 1;
        /* ѭ��������ע�⵽nums.size() - 1����Ϊʹ����i+1 */
        for(int i = 0; i < nums.size() - 1; i++){
            curdiff = nums[i + 1] - nums[i];
            /* С�ڵ���0Ϊ�������ֵ�����ҲҪ����ƽ����� */
            if ((curdiff > 0 && prediff <= 0) || (curdiff < 0 && prediff >= 0)){
                count++;
                /* ������Ÿ���prediff��ֵ��Ϊ�˷�ֹ�м���ƽ�� */
                prediff = curdiff;
            }
        }
        return count;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution solu;
    cout << solu.wiggleMaxLength(nums) << endl;
    return 0;
}