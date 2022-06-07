#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        for(int i = 0; i < (int)nums.size(); i++){
            nums[i] = nums[i] * nums[i];
        }
        int left = 0;
        int right = nums.size() - 1;
        int fastIndex = right;
        while(left <= right){
            if(nums[right] == max(nums[right], nums[left])){
                res[fastIndex--] = nums[right];
                right--;
            }else{
                res[fastIndex--] = nums[left];
                left++;
            }
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> a{-2,1,2,3};
    vector<int> res = solution.sortedSquares(a);
    for(auto num: res){
        cout << num << ", ";
    }
    cout << endl;
    return 0;
}