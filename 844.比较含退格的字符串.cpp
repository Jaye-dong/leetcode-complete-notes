#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    /* ԭ�ؽ��л��˲��� */
    int backSpace(string &s){
        int slowIndexS = s.size() - 1;
        /* back��ʾ�����˶��ٻ��˲��� */
        int back = 0;
        for(int fastIndexS = s.size() - 1; fastIndexS >= 0; fastIndexS--){
            /* ���û�л��˲��� */
            if(!back){
                if(s[fastIndexS] != '#'){
                    /* ����"��"���� */
                    s[slowIndexS--] = s[fastIndexS];
                }else{
                    /* ���˲��� + 1 */
                    back++;
                }
            }else{
                if(s[fastIndexS] == '#'){
                    /* ������˲���֮���ǻ��� back + 1 */
                    back++;
                }else{
                    /* �������˲��� */
                    back--;
                }
            }
        }
        return slowIndexS + 1;
    }
    bool backspaceCompare(string s, string t) {
        int newIndexS = backSpace(s);
        int newIndexT = backSpace(t);
        
        for(int i = newIndexS ; i < (int)s.size(); i++){
            cout << s[i] << ", ";
        }
        cout << endl;
        for(int i = newIndexT ; i < (int)t.size(); i++){
            cout << t[i] << ", ";
        }
        cout << endl;
        int indexS = s.size() - 1;
        int indexT = t.size() - 1;
        if(indexS - newIndexS != indexT - newIndexT) return false;
        while(indexS >= newIndexS && indexT >= newIndexT){
            if(s[indexS] != t[indexT]){
                return false;
            }
            indexS--;
            indexT--;
        }
        return true;
    }
    

};

int main(){
    Solution solution;
    // string s = "abc##";
    // string t = "bac##";

    string s = "bxj##tw";
    string t = "bxj###tw";
    cout << solution.backspaceCompare(s, t);

    return 0;
}