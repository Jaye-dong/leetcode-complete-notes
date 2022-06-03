#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        int fastIndex;
        for(fastIndex = 0; fastIndex < (int)nums.size(); fastIndex++){
            /* ����Ĺؼ��������˫ָ��ı��� */
            /* ��������ָ����Կ�����һ���µ����飬�ѿ�ָ�����������ĸ�ֵ��ȥ */
            if(nums[fastIndex] != 0){
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        /* ������Ҫ����ƶ���0��Ϊһ������ֵ������ֱ�Ӹ�����󼸸�Ԫ�� */
        while(slowIndex < fastIndex){
            nums[slowIndex++] = 0;
        }
    }
};

int main(){
    Solution solution;
    vector<int> a = {0,1,0,3,12};
    solution.moveZeroes(a);
    for(int i = 0; i < (int)a.size(); i++){
        cout << a[i] << ", ";
    }
    return 0;
}