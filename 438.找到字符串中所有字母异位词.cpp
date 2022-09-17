#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()){
            return vector<int>();
        }
        vector<int> res;
        int head = 0;
        int tail = p.size() - 1;
        int hash_s[26] = {0};
        int hash_p[26] = {0};
        for (int i = 0; i < (int)p.size(); i++){
            hash_s[s[i] - 'a']++;
            hash_p[p[i] - 'a']++;
        }
        int flag = 0;
        for( int i = 0; i < 26; i++){
            if(hash_s[i] != hash_p[i]){
                flag = 1;
            }
        }
        if( flag == 0 ){
            res.push_back(0);
        }
        
        while( tail < (int)s.size()-1 ){
            hash_s[s[head] - 'a']--;
            tail++;
            hash_s[s[tail] - 'a']++;
            head++;
            
            int flag = 0;
            for( int i = 0; i < 26; i++){
                if(hash_s[i] != hash_p[i]){
                    flag = 1;
                }
            }
            if( flag == 0 ){
                res.push_back(head);
            }
        }
        return res;
    }
};

int main(){

    string s = "cbaebabacd";
    string p = "abc";

    Solution solution;
    vector<int> res = solution.findAnagrams(s, p);
    for(int i = 0; i < (int)res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}