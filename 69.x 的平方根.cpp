#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        /* ���ֲ��ҵڶ���д�� */
        long long left = 0;
        long long right = x;
        while(left < right){
           long long mid = left + ((right - left) >> 1);
           long long mid2 = mid * mid;
           long long midPlus2 = (mid + 1) * (mid + 1);
            if( mid2 <= x && midPlus2 > x){
                return mid;
            }else if(midPlus2 <= x){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        /* ����left����Ϊ���mid + 1����ȷ�ģ����ʱ��left����mid + 1 */
        return left;
    }
};

int main(){
    vector<int> a = {4, 8, 1, 2147395599};
    Solution solution;
    for(int i = 0; i < (int)a.size(); i++){
        cout << solution.mySqrt(a[i]) << endl;
    }
    return 0;
}