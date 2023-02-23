#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit_sum = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            /* �����ʲ���ÿһ�죬ֻҪ�����Ҿ������ֲ����ţ��õ�ȫ�����ţ������̰�� */
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