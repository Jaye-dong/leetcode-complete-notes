#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    string replaceSpace(string s){
        int count = 0;
        for(int i = 0; i < (int)s.size(); i++){
            if (s[i] == ' '){
                count++;
            }
        }
        int oldSize = s.size();
        s.resize(s.size() + count * 2);
        
        for( int i = s.size()-1, j = oldSize-1; j < i; i--, j--){
            if(s[j] == ' '){
                s[i] = '0';
                s[--i] = '2';
                s[--i] = '%';
            }else{
                s[i] = s[j];
            }
        }
        return s;
    }
};

int main(){
    string s;
    s = "we are happy";
    Solution solution;
    string res = solution.replaceSpace(s);
    cout << res;
    return 0;
}