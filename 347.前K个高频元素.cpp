#include <queue>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    class comp{
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int,int> &rhs){
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k){
        vector<int> res(k);
        unordered_map<int, int> hash;
        for(int i = 0; i < (int)nums.size(); i++){
            hash[nums[i]]++;
        }
        // vector<pair<int,int> > means heap use this data struct
        // the consise definition is priority_queue<pair<int,int>> pri_que;
        priority_queue<pair<int,int>, vector<pair<int,int> >, comp> pri_que; 

        for(auto it = hash.begin(); it != hash.end(); it++){
            pri_que.push(*it);
            if((int)pri_que.size() > k){
                pri_que.pop();
            }
        }
        int j = k - 1;
        while(!pri_que.empty()){
            res[j--] = pri_que.top().first;
            pri_que.pop();
        }
        return res;
    }
    
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int k;
    cin >> k;
    Solution solution;
    vector<int> res = solution.topKFrequent(nums, k);
    for(int a : res){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}   