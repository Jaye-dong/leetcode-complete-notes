#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;

        for(int fastIndex = 0; fastIndex < (int)nums.size(); fastIndex++){
            /* slowIndex相当于新数组 */
            if(nums[fastIndex] != val){
                /* 如果fastIndex不等于val，则把值加入新数组 */
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            
            }
        }
        return slowIndex;
    }
};
int main(){
    Solution solution;
    vector<int> a = {1, 2, 3, 2, 4};
    int len = solution.removeElement(a, 2);
    for(int i = 0; i < len; i++){
        cout << a[i] << ", ";
    }
    cout << endl;
    return 0;
}