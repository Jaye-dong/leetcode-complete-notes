#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit_sum = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            /* 把利率拆解成每一天，只要有利我就做，局部最优，得到全局最优，这就是贪心 */
            int profit = prices[i + 1] -prices[i];
            if (profit > 0) {
                profit_sum += profit;
            }
        }
        return profit_sum;
    }
};


int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    cout << "maxProfit: " << Solution().maxProfit(prices) << endl;
    return 0;
}