#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    string removeDuplicates(string s){
        if(s.size() == 0) return s;
        string st;

        for (int i = 0; i < (int)s.size(); i++){
            if(st.empty()){
                st.push_back(s[i]);
                continue;
            }
            if(s[i] != st.back())
                st.push_back(s[i]);
            else{
                st.pop_back();
            }
        }
        return st;
    }
};

int main(){
    string s;
    cin >> s;
    Solution solution;
    cout << solution.removeDuplicates(s);
    return 0;
}