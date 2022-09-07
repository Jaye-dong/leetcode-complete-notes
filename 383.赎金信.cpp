#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) return false;
        int hash_ransomNote[128] = {0};
        int hash_magazine[128] = {0};
        for(int i = 0; i < (int)ransomNote.size(); i++){
            hash_ransomNote[(size_t)ransomNote[i]]++;
        }
        for(int i = 0; i < (int)magazine.size(); i++){
            hash_magazine[(size_t)magazine[i]]++;
        }
        for(int i = 0;i < 128;i++){
            if(hash_magazine[i] < hash_ransomNote[i]){
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