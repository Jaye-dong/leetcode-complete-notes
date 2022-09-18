#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < (int)nums.size(); i++){
            if(hash.count(target - nums[i])){
                return vector<int>{hash[target - nums[i]],i};
            }
            hash[nums[i]] = i;
        }
        return vector<int>();
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    while(n--){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int target;
    cin >> target;

    Solution solution;
    vector<int> res = solution.twoSum(nums, target);
    for(int i = 0; i < (int)res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}