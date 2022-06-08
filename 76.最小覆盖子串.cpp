#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:

    string minWindow(string s, string t) {
        /* ��������hash���¼��ĸ���ֵĴ��� */
        unordered_map<char, int> hs, ht;
        for(auto c: t) ht[c]++;
        string res;
        /* ��¼s������t�Ĵ��� */
        int cnt = 0;
        for(int i = 0, j = 0; i < (int)s.size(); i++){
            /* ����s[i],���ڼ�¼��+1 */
            hs[s[i]]++;
            /* ���������t�е���ĸ�� cnt++ */
            if( hs[s[i]] <= ht[s[i]]) cnt++;
            while(hs[s[j]] > ht[s[j]]) hs[s[j++]]--;
            /* ������еĴ����㹻 */
            if(cnt == (int)t.size()){
                /* ���res�ǿյģ����ߵ�ǰ����Ҫ��֮ǰ�Ľ��С������res */
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