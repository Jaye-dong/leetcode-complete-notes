#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    string reverseWords(string s){
        int slow = 0;
        
        for(int fast = 0; fast < (int)s.size(); fast++){
            if(s[fast] != ' '){
                if(slow != 0){
                    s[slow++] = ' ';
                }
                while(fast < (int)s.size() && s[fast] != ' '){
                    s[slow++] = s[fast++];
                }
                
            }
        }
        s.resize(slow);
        
        reverse(s.begin(), s.end());
        int start = 0;
        for(int i = 0; i <= (int)s.size(); i++){
            if( i == (int)s.size() || s[i] == ' '){
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};

int main(){
    string s = "  hello world  ";
    Solution solution;
    s = solution.reverseWords(s);
    cout << s;
    return 0;
}