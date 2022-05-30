#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slowIndex = 1;
        for(int fastIndex = 1; fastIndex < (int)nums.size(); fastIndex++){
            /* 如果不等于前一个，就放入新的数组 */
            if(nums[fastIndex] != nums[fastIndex - 1]){
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

int main(){
    vector<int> a = {1, 1, 1, 2, 3, 3};
    Solution solution;
    int len = solution.removeDuplicates(a);
    for(int i = 0; i < len; i++){
        cout << a[i] << ", ";
    }
    cout << endl;
    return 0;
}
