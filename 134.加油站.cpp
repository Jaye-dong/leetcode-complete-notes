#include <iostream>
#include <vector>
#include <climits>


using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        /* �����ⷨ */
        for(int i = 0; i < cost.size(); i++){
            int rest = gas[i] - cost[i];
            int index = (i + 1) % cost.size();
            /* ��û�г���ȱ����û�е����ʱ�� */
            while(rest >= 0 && index != i){
                rest += gas[index] - cost[index];
                index = (index + 1) % cost.size();
            }
            /* ������껹���ͣ�˵����i�������� */
            if (rest >= 0) {
                return i;
            }
        }
        /* �Ҳ��� */
        return -1;
    }

    int canCompleteCircuit2(vector<int>& gas, vector<int>& cost) {
        /* ȫ�����ŷ� */
        int curSum = 0;
        /* ���ڴ�Ź����е���ȱ�͵� */
        int min = INT_MAX;
        /* Ĭ�ϴ�0��ʼ */
        for(int i = 0; i < cost.size(); i++){
            int rest = gas[i] - cost[i];
            curSum += rest;
            if ( curSum < min){
                min = curSum;
            }
        }
        /* ���1: ���е��Ͳ������е�cost */
        if (curSum < 0){
            return -1;
        }

        /* ���2: ��0����û�г���ȱ�͵���� */
        if (min >= 0) {
            return 0;
        }
        /* ���3����0����ȱ�ͣ�Ҫ��0�ġ�ǰ�桱�ҳ����㣬�ֲ����ȱ�� */
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
        /* ̰��˼�� */
        /* �������룬����������Ĵ����������������ܹ�����һ�� */
        /* �Ƶ������е㸴�Ӿ��忴https://programmercarl.com/0134.%E5%8A%A0%E6%B2%B9%E7%AB%99.html#%E8%B4%AA%E5%BF%83%E7%AE%97%E6%B3%95-%E6%96%B9%E6%B3%95%E4%BA%8C */
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++){
            int rest = gas[i] - cost[i];
            curSum += rest;
            totalSum += rest;
            /* �������С��0 ˵��ǰ��һ�ε�totalSumС��0 */
            if (curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        /* ����������Ĵ���������˵���Ͳ��� */
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