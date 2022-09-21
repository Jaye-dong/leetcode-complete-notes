#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            swap(s[left++], s[right--]);
        }
    }
};
int main(){
    string s;
    cin >> s;
    Solution solution;
    vector<char> ss;
    for(char c : s){
        ss.push_back(c);
    }
    solution.reverseString(ss);
    for(char c : ss){
        cout << c;
    }
    return 0;
}