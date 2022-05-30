#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /* ����һ���ж��Ƿ�����ı�־ */
        int overflow = 1;
        /* �����һ����ʼ+1 */
        int index = digits.size() - 1;
        while(overflow){
            
            if(index >= 0){
                
                int temp = digits[index];
                digits[index] = (temp + 1) % 10;
                /* ���������ˣ����������־Ϊ0 */
                if(!(temp + 1 == 10)){
                    overflow = 0;
                } 
                index--;
            }else{
                /* ����ӵ���һλ���������˵99 + 1����digitsǰ�����һ��1 */
                digits.insert(digits.begin(), 1);
                break;
            }

        }
        return digits;
    }
};

int main(){
    vector<int> a = {2, 1, 9, 9};
    Solution solution;
    a = solution.plusOne(a);
    for(int i = 0; i < (int)a.size(); i++){
        cout << a[i] << ", ";
    }
    cout << endl;
    return 0;
}