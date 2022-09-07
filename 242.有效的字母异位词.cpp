#include <string>
#include <iostream>
using namespace std;
class Solution{
public:
    bool isAnagram(string s, string t){
        int hash_s[128] = {0};
        int hash_t[128] = {0};
        for(int i = 0; i < (int)s.size(); i++){
            hash_s[(size_t)s[i]]++;
        }
        for(int i = 0; i < (int)t.size(); i++){
            hash_t[(size_t)t[i]]++;
        }
        for(int i = 0;i < 128;i++){
            if(hash_s[i] != hash_t[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    cout << solution.isAnagram("rat", "car");
    return 0;
}