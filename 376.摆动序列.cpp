#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        /* 如果小于等于1表示序列长度只有这么长 */
        if (nums.size() <= 1){
            return nums.size();
        }
        /* 设置两个变量来看之间的差值 */
        int prediff = 0;
        int curdiff = 0;
        /* 初值是1，因为只要有一个序列，一定至少长度为 2 */
        int count = 1;
        /* 循环遍历，注意到nums.size() - 1，因为使用了i+1 */
        for(int i = 0; i < nums.size() - 1; i++){
            curdiff = nums[i + 1] - nums[i];
            /* 小于等于0为了满足初值情况，也要覆盖平坡情况 */
            if ((curdiff > 0 && prediff <= 0) || (curdiff < 0 && prediff >= 0)){
                count++;
                /* 在里面才更新prediff的值，为了防止中间有平坡 */
                prediff = curdiff;
            }
        }
        return count;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution solu;
    cout << solu.wiggleMaxLength(nums) << endl;
    return 0;
}