#include <iostream>
#include <vector>
#include <climits>


using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        /* 暴力解法 */
        for(int i = 0; i < cost.size(); i++){
            int rest = gas[i] - cost[i];
            int index = (i + 1) % cost.size();
            /* 在没有出现缺油且没有到起点时候 */
            while(rest >= 0 && index != i){
                rest += gas[index] - cost[index];
                index = (index + 1) % cost.size();
            }
            /* 如果跑完还有油，说明从i出发可以 */
            if (rest >= 0) {
                return i;
            }
        }
        /* 找不到 */
        return -1;
    }

    int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
        /* 全局最优法 */
        int curSum = 0;
        /* 用于存放过程中的最缺油点 */
        int min = INT_MAX;
        /* 默认从0开始 */
        for(int i = 0; i < cost.size(); i++){
            int rest = gas[i] - cost[i];
            curSum += rest;
            if ( curSum < min){
                min = curSum;
            }
        }
        /* 情况1: 所有的油不及所有的cost */
        if (curSum < 0){
            return -1;
        }

        /* 情况2: 从0出发没有出现缺油的情况 */
        if (min >= 0) {
            return 0;
        }
        /* 情况3：从0出发缺油，要从0的“前面”找出发点，弥补这个缺油 */
        for(int i = gas.size() - 1; i >= 0; i--){
            int rest = gas[i] - cost[i];
            min += rest;
            if (min >= 0){
                return i;
            }
        }
        return -1;
    }

    int canCompleteCircuit3(vector<int>& gas, vector<int>& cost) {
        /* 贪心思想 */
        /* 反过来想，如果整个消耗大于油量，不可能能够环形一周 */
        /* 推导可能有点复杂具体看https://programmercarl.com/0134.%E5%8A%A0%E6%B2%B9%E7%AB%99.html#%E8%B4%AA%E5%BF%83%E7%AE%97%E6%B3%95-%E6%96%B9%E6%B3%95%E4%BA%8C */
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++){
            int rest = gas[i] - cost[i];
            curSum += rest;
            totalSum += rest;
            /* 如果出现小于0 说明前面一段的totalSum小于0 */
            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        /* 如果整个消耗大于油量，说明油不够 */
        if (totalSum < 0) {
            return -1;
        }

        return start;
    }
};


int main(){
    int n;
    cin >> n;
    vector<int> gas(n);
    for(int i = 0; i < n; i++){
        cin >> gas[i];
    }
    vector<int> cost(n);
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    
    cout << Solution().canCompleteCircuit3(gas, cost) << endl;

    return 0;
}