#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hash;
        int count = 0;
        for(int a : nums1){
            for(int b: nums2){
                hash[a+b]++;
            }
        }
        for(int c : nums3){
            for(int d: nums4){
                if(hash[0-(c + d)]){
                    count += hash[0-(c + d)];
                }
            }
        }
        return count;
    }
};

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int> > nums(n, vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> nums[i][j];
        }
    }
    Solution solution;
    cout << solution.fourSumCount(nums[0], nums[1], nums[2], nums[3]);
    return 0;
}