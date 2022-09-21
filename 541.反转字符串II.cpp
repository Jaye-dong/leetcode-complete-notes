#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:
    void reverseS(string &s, int left, int right){
        while(left < right){
            swap(s[left++], s[right--]);
        }
    }
    string reverseStr(string s, int k){
        for(int i = 0; i < (int)s.size(); i += (2 * k)){
            if(i + k <= (int)s.size()){
                reverseS(s, i, i + k - 1);
            }else{
                reverseS(s, i, i + (s.size() % k) - 1);
            }
        }
        return s;
    }
};

int main(){
    int k;
    cin >> k;
    string s;
    cin >> s;
    Solution solution;
    string res = solution.reverseStr(s, k);
    cout << res;
    return 0;
}