#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
    bool isValid(string s){
        stack<char> st;
        for(char c : s){
            if(c == '(') st.push(')');
            else if(c == '[') st.push(']');
            else if(c == '{') st.push('}');
            else if( st.empty() || c != st.top()) return false;
            else if(c == st.top()) st.pop();
        }
        return st.empty();
    }
};

int main(){
    string s;
    cin >> s;
    Solution solution;
    cout << solution.isValid(s);
    return 0;
}