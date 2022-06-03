#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        int fastIndex;
        for(fastIndex = 0; fastIndex < (int)nums.size(); fastIndex++){
            /* 解题的关键在于理解双指针的本质 */
            /* 本质上慢指针可以看作是一个新的数组，把快指针满足条件的赋值过去 */
            if(nums[fastIndex] != 0){
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        /* 并不需要真的移动，0作为一个特殊值，可以直接赋给最后几个元素 */
        while(slowIndex < fastIndex){
            nums[slowIndex++] = 0;
        }
    }
};

int main(){
    Solution solution;
    vector<int> a = {0,1,0,3,12};
    solution.moveZeroes(a);
    for(int i = 0; i < (int)a.size(); i++){
        cout << a[i] << ", ";
    }
    return 0;
}