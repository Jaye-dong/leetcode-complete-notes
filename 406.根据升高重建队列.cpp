#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;


class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people){
        /* 首先，按身高排序 */
        sort(people.begin(), people.end(), cmp);
        /* 使用list链表，插入效率高 */
        list<vector<int>> vecSorted;
        for(int i = 0; i < people.size(); i++){
            int position = people[i][1];
            list<vector<int>>::iterator it = vecSorted.begin();
            while(position--){
                it++;
            }
            vecSorted.insert(it, people[i]);
        }
        /* 最后使用链表创建临时变量 */
        return vector<vector<int>>(vecSorted.begin(), vecSorted.end());
    }
};

void transStr2Nums(string s, vector<vector<int>> &people, char delim){
    int start = 0;
    int i = 0;
    vector<int> vec(2,0);
    while (i < s.size()){
        i++;
        if(i == s.size() || s[i] == delim){
            string temp = s.substr(start, i - start);
            if(temp[0] == '['){
                vec[0] = atoi(temp.substr(1,temp.size() - 1).c_str());
            }
            if(temp[temp.size() - 1] == ']'){
                vec[1] = atoi(temp.substr(0,temp.size() - 1).c_str());
                people.push_back(vec);
                vec.assign(2,0);
            }
            start = i + 1;
        }
    }
}

int main(){
    string s;
    vector<vector<int>> people;
    getline(cin, s);

    transStr2Nums(s, people, ',');
    
    vector<vector<int>> res = Solution().reconstructQueue(people);
    for(auto v: res){
        for(auto a : v){
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}