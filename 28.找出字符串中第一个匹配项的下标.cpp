#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    void getNext(int *next, string s){
        int j = 0;
        next[j] = 0;
        for(int i = 1; i < (int)s.size(); i++){
            while(s[i] != s[j] && j > 0){
                j = next[j-1];
            }
            if(s[i] == s[j]){
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle){
        
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for(int i = 0; i < (int)haystack.size(); i++){
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j-1];
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == (int)needle.size()){
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};

int main(){
    string s,t;
    cin >> s >> t;
    Solution solution;
    cout << solution.strStr(s,t);
    return 0;
}