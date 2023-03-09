#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /* ȷ��4�� */
        // 1.�������: �����ı����Ǿ����ܵؽ�ʯͷ��Ϊ��ͬ��С������ */
        //   �����������ȷ��Ϊ���������һ��
        // 2.���������������stones[i], ��ֵҲ��stones[i]
        // 3.������������ʱ��sum - target�ı������ܱ����������*2���ǽ��
        // 4.������Ʒֻ�ܷ���һ��
        int sum = 0;
        for(const int& a : stones){
            sum += a;
        }
        int target = sum / 2;
        /* ��ʼ01���� */
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