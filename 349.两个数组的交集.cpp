#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;


class Solution{

public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool> hash;
        vector<int> res;
        if(nums1.size() > nums2.size()) return intersection(nums2, nums1);
        for(int i = 0; i < (int)nums1.size(); i++){
            hash[nums1[i]] = true;
        }
        for(int i = 0; i < (int)nums2.size(); i++){
            if(hash[nums2[i]]){
                res.push_back(nums2[i]);
                nums2[i] = false;
            }
        }
        return res;
    }
};
int main(){
    vector<int> s1;
    vector<int> s2;
    int n;
    int m;
    cin >> n;
    while(n--){
        int temp;
        cin >> temp;
        s1.push_back(temp);
    }
    cin >> m;
    while(m--){
        int temp;
        cin >> temp;
        s2.push_back(temp);
    }

    Solution solution;
    vector<int> res = solution.intersection(s1, s2);
    for(int i = 0; i < (int)res.size(); i++){
        cout << res[i] << endl;
    }
    return 0;
}