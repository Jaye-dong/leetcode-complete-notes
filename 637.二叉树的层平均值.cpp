#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
class Solution{
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        if(root == nullptr) return res;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> vec;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            double mean_level = 0;
            for(int i = 0; i < (int)vec.size(); i++){
                mean_level += vec[i];
            }
            mean_level = mean_level/vec.size();
            res.push_back(mean_level);
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
    int i = 0;
    unordered_map<int, TreeNode*> hash;
    TreeNode* root;
    while(i < n){
        if(i == 0){
            hash[i] = new TreeNode(nums[i]);
            root = hash[i];
        }
        if(i*2+1 < n){
            if(nums[i*2+1] != -1){
                hash[i*2+1] = new TreeNode(nums[i*2+1]);
                hash[i]->left = hash[i*2+1];
            }
        }
        if(i*2+2 < n){
            if(nums[i*2+2] != -1){
                hash[i*2+2] = new TreeNode(nums[i*2+2]);
                hash[i]->right = hash[i*2+2];
            }
        }
        i++;
    }
    Solution solution;
    vector<double> res = solution.averageOfLevels(root);
    for(double a : res){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}