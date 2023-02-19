#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int result = 1;
        int curdiff = 0;
        int prediff = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            curdiff = nums[i+1] - nums[i];
            if ((curdiff > 0 && prediff <= 0) || (curdiff < 0 && prediff >= 0)){
                result++;
                prediff = curdiff;
            }
        }
        return result;
    }
};


int main(){
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    Solution solution;
    cout << solution.wiggleMaxLength(nums) << endl;

    return 0;
}