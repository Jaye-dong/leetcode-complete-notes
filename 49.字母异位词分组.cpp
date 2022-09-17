#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution{
public:
    string encodeAnagram(string a){
        string res;
        int hash[26] = {0};
        for(int i = 0;i < (int)a.size(); i++){
            hash[a[i]-'a']++;
        }
        
        for(int i = 0;i < 26;i++){
            res.push_back('a'+i);
            res.push_back(hash[i]-'0');
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;
        for(int i = 0; i < (int)strs.size(); i++){
            string encoded = encodeAnagram(strs[i]);
            if(hash.count(encoded)){
                hash[encoded].push_back(strs[i]);
            }else{
                vector<string> temp;
                temp.push_back(strs[i]);
                hash[encoded] = temp;
            }
        }
        for(auto it = hash.begin(); it != hash.end(); it++){
            res.push_back(it->second);
        }
        return res;
        
    }
};
int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution solution;
    vector<vector<string>> res = solution.groupAnagrams(strs);
    for(int i = 0; i < (int)res.size(); i++){
        for (int j = 0; j < (int)res[i].size(); j++){
            cout << res[i][j]<< " ";
        }
        cout << endl;
    }
    return 0;
}