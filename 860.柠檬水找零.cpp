#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills){
        int five = 0;
        int ten = 0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                five++;
            } else if(bills[i] == 10){
                if(five != 0){
                    five--;
                    ten++;
                }else{
                    return false;
                }
            }else if(bills[i] == 20){
                if (ten != 0 && five != 0){
                    ten--;
                    five--;
                } else if(five >= 3){
                    five -= 3;
                } else{
                    return false;
                }
            }
        }
        return true;
    }
};

void transStr2Nums(const string& s, vector<int>& nums, char delim){
    int start = 0;
    int i = 0;
    while( i < s.size()){
        i++;
        if( i == s.size() || s[i] == delim){
            string temp = s.substr(start, i - start);
            nums.push_back(atoi(temp.c_str()));
            start = i + 1;
        }
    }
}

int main(){
    vector<int> bills;
    string s;
    
    getline(cin, s);

    transStr2Nums(s, bills, ',');

    cout << Solution().lemonadeChange(bills) << endl;

    return 0;
}