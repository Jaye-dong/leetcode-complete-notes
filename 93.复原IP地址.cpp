#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Solution{
public:
    vector<string> res;
    bool isValid(const string &s, int start, int end){
        if(start > end) {
            return false;
        }
        /* ≈–∂œ«∞÷√0 */
        if (s[start] == '0' && start != end) return false;
        int num = 0;
        for(int i = start; i <= end; i++){
            if( s[i] < '0' || s[i] > '9'){
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if(num > 255){ 
                return false;
            }
        }
        return true;
    }
    void backtracking(string &s, int startIndex, int dotCnt){
        if(dotCnt == 3){
            if(isValid(s, startIndex, s.size() - 1)){
                res.push_back(s);
                return;
            }
        }
        for(int i = startIndex; i < s.size(); i++){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1, '.');
                dotCnt++;
                backtracking(s, i + 2, dotCnt);
                dotCnt--;
                s.erase(s.begin() + i + 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if(s.size() < 4 || s.size() > 12) return res;
        backtracking(s, 0, 0);
        return res;
    }
    
};


int main(){
    string s;
    cin >> s;
    Solution solution;
    vector<string> res = solution.restoreIpAddresses(s);
    for(auto v : res){
        cout << v << endl;
    }
    return 0;
}