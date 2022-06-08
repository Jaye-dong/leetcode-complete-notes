#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:

    string minWindow(string s, string t) {
        /* 定义两个hash表记录字母出现的次数 */
        unordered_map<char, int> hs, ht;
        for(auto c: t) ht[c]++;
        string res;
        /* 记录s中命中t的次数 */
        int cnt = 0;
        for(int i = 0, j = 0; i < (int)s.size(); i++){
            /* 遇到s[i],就在记录里+1 */
            hs[s[i]]++;
            /* 如果命中了t中的字母， cnt++ */
            if( hs[s[i]] <= ht[s[i]]) cnt++;
            while(hs[s[j]] > ht[s[j]]) hs[s[j++]]--;
            /* 如果命中的次数足够 */
            if(cnt == (int)t.size()){
                /* 如果res是空的，或者当前长度要比之前的结果小，更新res */
                if( res.empty() || i - j + 1 < (int)res.size()){
                    res = s.substr(j, i - j + 1);
                }
            }
        }
        return res;
    }
};

int main(){

    Solution solution;
    string s = "bacaaaabc";
    string t = "bc";
    cout << solution.minWindow(s, t) << endl; 
    
    return 0;
}