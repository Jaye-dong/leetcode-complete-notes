#include <string>
#include <iostream>
using namespace std;
class Solution{
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for(char c : magazine){
            hash[c - 'a']++;
        }
        for(char c : ransomNote){
            hash[c - 'a']--;
            if(hash[c - 'a'] < 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    cout << solution.canConstruct("rat", "cart");
    return 0;
}