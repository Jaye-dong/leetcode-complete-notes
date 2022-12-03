#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    vector<int> minOperations(string boxes) {
        // dp[i]��ʾ��Ҫ���ٸ������ܹ���ÿ����Ū����
        // ���ƹ�ʽ
        // dp[i+1] = dp[i] + rightCnt*(-1) + leftCnt*(1);
        // rightCnt��ʾ�ұߵģ�leftCnt��ʾ��ߵĸ���
        // rightCnt��ʾ[i,..) leftCnt��ʾ[0,i)
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