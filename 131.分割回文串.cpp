#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> PalindromeMatrix;
    bool isPalindrome(const string &s, int left, int right){
        for(int i = left, j = right; i <= j; i++, j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(int left, int right){
        return PalindromeMatrix[left][right];
    }
    void computePalindrome(const string &s){
        PalindromeMatrix.resize(s.size(), vector<bool>(s.size(), false));
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = i; j < s.size(); j++){
                if(i == j){
                    PalindromeMatrix[i][j] = true;
                }else if(j - i == 1){
                    PalindromeMatrix[i][j] = (s[i] == s[j]);
                }else{
                    PalindromeMatrix[i][j] = (s[i] == s[j] && PalindromeMatrix[i+1][j-1]);
                }
            }
        }
    }
    void backtracking(string s, int startIndex){
        if(startIndex >= s.size()){
            res.push_back(path);
            return;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(isPalindrome(startIndex, i)){
                path.push_back(s.substr(startIndex, i - startIndex + 1));
            }else{
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        computePalindrome(s);
        backtracking(s, 0);
        return res;
    }
};

int main(){
    string s;
    cin >> s;
    Solution solution;
    vector<vector<string>> res = solution.partition(s);
    for(auto v : res){
        for(auto a : v){
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}