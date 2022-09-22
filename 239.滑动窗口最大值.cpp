#include <stack>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>

using namespace std;
class Solution{
private:
    class MyQueue{
    public:
        deque<int> dq;
        void pop(int val){
            if(!dq.empty() && dq.front() == val){
                dq.pop_front();
            }
        }
        void push(int val){
            while(!dq.empty() && dq.back() < val){
                dq.pop_back();
            }
            dq.push_back(val);
        }
        int getMaxValue(){
            return dq.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue q;
        vector<int> res(nums.size() - k + 1);
        int j = 0;
        for(int i = 0; i < k; i++){
            q.push(nums[i]);
        }
        res[j++] = q.getMaxValue();
        for(int i = k; i < (int)nums.size(); i++){
            q.pop(nums[i-k]);
            q.push(nums[i]);
            res[j++] = q.getMaxValue();
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
    vector<int> res = solution.maxSlidingWindow(nums, k);
    for(int a : res){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}