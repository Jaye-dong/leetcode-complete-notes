#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    /* 原地进行回退操作 */
    int backSpace(string &s){
        int slowIndexS = s.size() - 1;
        /* back表示积累了多少回退操作 */
        int back = 0;
        for(int fastIndexS = s.size() - 1; fastIndexS >= 0; fastIndexS--){
            /* 如果没有回退操作 */
            if(!back){
                if(s[fastIndexS] != '#'){
                    /* 放入"新"数组 */
                    s[slowIndexS--] = s[fastIndexS];
                }else{
                    /* 回退操作 + 1 */
                    back++;
                }
            }else{
                if(s[fastIndexS] == '#'){
                    /* 如果回退操作之后还是回退 back + 1 */
                    back++;
                }else{
                    /* 抵消回退操作 */
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