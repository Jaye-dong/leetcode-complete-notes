#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    vector<int> minOperations(string boxes) {
        // dp[i]表示需要多少个步骤能够把每个球弄过来
        // 递推公式
        // dp[i+1] = dp[i] + rightCnt*(-1) + leftCnt*(1);
        // rightCnt表示右边的，leftCnt表示左边的个数
        // rightCnt表示[i,..) leftCnt表示[0,i)
        vector<int> dp(boxes.size());
        int rightCnt = 0;
        int leftCnt = 0;
        for(size_t i = 0; i < boxes.size(); i++){
            if(boxes[i] == '1'){
                dp[0] += i;
                rightCnt++;
            }
        }

        for(size_t i = 1; i < dp.size(); i++){
            if(boxes[i-1] == '1'){
                leftCnt++;
                rightCnt--;
            }
            dp[i] = dp[i-1] + rightCnt*(-1) + leftCnt;
        }
        return dp;
    }   
};

int main(){
    string boxes;
    cin >> boxes;
    Solution solution;
    vector<int> res = solution.minOperations(boxes);
    for(auto a : res){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}