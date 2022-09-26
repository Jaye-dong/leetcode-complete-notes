#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
class Solution{
public:
    void dfs(TreeNode* cur, vector<int> &res){
        if(cur == nullptr){
            return;
        }
        dfs(cur->left, res);
        res.push_back(cur->val);
        dfs(cur->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        dfs(root, res);
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
    TreeNode * root;
    while(i < (int)nums.size()){
        if(i == 0){
            hash[i] = new TreeNode(nums[i]);
            root = hash[i];
        }
        if(i*2+1 < (int)nums.size()){
            hash[i*2+1] = new TreeNode(nums[i*2+1]);
            hash[i]->left = hash[i*2+1];
        }
        if(i*2+2 < (int)nums.size()){
            hash[i*2+2] = new TreeNode(nums[i*2+2]);
            hash[i]->right = hash[i*2+2];
        }
        i++;
    }
    Solution solution;
    vector<int> res = solution.inorderTraversal(root);
    for(int a : res){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}