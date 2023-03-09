#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /* 确定4点 */
        // 1.背包体积: 这道题的本质是尽可能地将石头分为相同大小的两组 */
        //   背包体积可以确定为最大重量的一半
        // 2.背包放入的重量是stones[i], 价值也是stones[i]
        // 3.当背包被放满时，sum - target的背包所能背的最大重量*2就是结果
        // 4.背包物品只能放入一次
        int sum = 0;
        for(const int& a : stones){
            sum += a;
        }
        int target = sum / 2;
        /* 开始01背包 */
        vector<int> dp(target + 1, 0);
        for(int i = 0; i < stones.size(); i++){
            for(int j = target; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> stones(n);
    for(auto& stone : stones){
        cin >> stone;
    }

    cout << Solution().lastStoneWeightII(stones) << endl;

    return 0;
}