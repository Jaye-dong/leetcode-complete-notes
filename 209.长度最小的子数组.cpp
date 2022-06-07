#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;
class Solution {
public:

    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int sum = 0;
        for(int i = 0, j = 0; j < (int)nums.size(); j++){
            /* ÿ�ΰ�j���� */
            sum += nums[j];
            while(sum >= target){
                /* ȡ�����鳤�ȣ�ֱ��С��targetΪֹ */
                minLen = min(minLen, j - i + 1);
                /* ȥ��i */
                sum -= nums[i++];
            }
        }
        
        return minLen == INT_MAX? 0 : minLen;
    }
};

int main(){
    Solution solution;
    vector<int> a = {2,3,1,2,4,3};
    cout << solution.minSubArrayLen(7, a) << endl;
    return 0;
}