#include <iostream>
#include <string>


using namespace std;



class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        /* ת��Ϊ�ַ��� */
        string num = to_string(n);

        /* ��¼��ʼ��ֵΪ9��λ�ã�����size()��Ϊ�˼���ԭ������������ */
        int flag = num.size();

        /* �Ӻ���ǰ������̰�ľ�������������ס */
        for(int i = num.size() - 1; i > 0; i--){
            /* ���ǰ��ıȺ����Ҫ��,ǰ��ļ�һ���������Ϊ9 */
            if(num[i-1] > num[i]){
                flag = i;
                num[i-1]--;
            }
        }

        /* ��flag��ʼ��Ϊ9 */
        for(int i = flag; i < num.size(); i++){
            num[i] = '9';
        }
        /* �ַ���ת��Ϊ���� */
        return stoi(num);
    }
};


int main(){
    int n;
    while(cin >> n){
        cout << Solution().monotoneIncreasingDigits(n) << endl;
    }
    
    
    return 0;
}