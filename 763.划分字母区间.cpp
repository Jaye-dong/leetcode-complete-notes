#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s){
        /* ͳ��ÿ�����������ֵ�λ�� */
        int hash[26] = {0};
        for(int i = 0; i < s.size(); i++){
            hash[s[i] - 'a'] = i;
        }
        vector<int> res;
        int len = 0;
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            /* ���³��� */
            len = max(hash[s[i] - 'a'], len);
            if(len == i){
                res.push_back(i - start + 1);
                start = len + 1;
            }
        }
        return res;
    }
};


int main(){
    string s;
    cin >> s;
    vector<int> res = Solution().partitionLabels(s);
    for(int a : res){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}