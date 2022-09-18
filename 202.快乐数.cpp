#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int num = n;
        unordered_map<int,bool> hash;
        while(num != 1){
            if(hash[num]) {
                return false;
            }
            hash[num] = true;
            int sum = 0;
            while(num){
                sum += (num % 10) * (num % 10);
                num /= 10;
            }
            num = sum;
        }
        return true;
    }
};

int main(){
    Solution solution;
    int n = 19;
    cout << solution.isHappy(n) << endl;
    int m = 2;
    cout << solution.isHappy(m) << endl;
    return 0;
}