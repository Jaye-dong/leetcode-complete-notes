#include <iostream>
#include <string>

using namespace std;

class Solution1{
/*
遍历一遍，然后在通过hash，实际上是分桶思想
*/
public:
    int secondHighest(string s) {
        int hash[10] = {0};
        for(int i = 0; i < (int)s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9' ){
                hash[s[i]-'0'] = 1;
            }
        }
        int count = 0;
        for(int i = 9; i >= 0; i--){
            if(hash[i]){
                count++;
            }
            if(count == 2){
                return i;
            }
        }
        return -1;
    }
};


class Solution2{
/*
遍历一遍，用两个数保存最大值和最小值
*/
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for(auto &c : s){
            if(isdigit(c)){
                int v = c - '0';
                if(v > first){
                    second = first;
                    first = v;
                }else if(v > second && v < first){
                    second = v;
                }
            }
        }
        return second;
    }
};


class Solution3{
/*
用位运算代替hash
*/
public:
    int secondHighest(string s) {
        int mask = 0;
        for(auto &c : s){
            if(isdigit(c)){
                int v = c - '0';
                mask |= 1 << v;
            }
        }
        
        for(int i = 9, cnt = 0; i >= 0; i--){
            if(mask >> i & 1){
                cnt++;
            }
            if(cnt == 2){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    string s;
    cin >> s;
    Solution3 solution;
    cout << solution.secondHighest(s) << endl;
    return 0;
}