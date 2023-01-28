#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution{
public:
    string s;
    vector<string> result;
    string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    void backtracking(const string& digits, int index){
        if(index == digits.size()){
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letter = letterMap[digit];
        for(int i = 0; i < letter.size(); i++){
            s.push_back(letter[i]);
            backtracking(digits, index + 1);
            s.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "") return vector<string>{};
        backtracking(digits, 0);
        return result;
    }
};

int main(){
    string str = "";
    cin >> str;
    Solution solution;
    vector<string> res = solution.letterCombinations(str);

    for(auto letter : res){
        cout << letter << " ";
    }
    cout << endl;
    
    return 0;
}