#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution{
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

int main(){
    
    string s;
    cin >> s;
    int n;
    cin >> n;
    Solution solution;
    string res = solution.reverseLeftWords(s, n);
    cout << res;
    return 0;
}