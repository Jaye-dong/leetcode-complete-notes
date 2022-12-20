#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(TreeNode* cur, int count){
        if(!cur->left && !cur->right && count == 0){
            res.push_back(path);
            return;
        }
        if(!cur->left && !cur->right) return;

        if(cur->left){
            path.push_back(cur->left->val);
            count -= cur->left->val;
            dfs(cur->left, count);
            count += cur->left->val;
            path.pop_back();
        }
        if(cur->right){
            path.push_back(cur->right->val);
            count -= cur->right->val;
            dfs(cur->right, count);
            count += cur->right->val;
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return res;
        path.push_back(root->val);
        dfs(root, targetSum - root->val);
        
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
    hash[i] = new TreeNode(nums[i]);
    TreeNode* root = hash[i];
    while(i < n){
        int L = i * 2 + 1;
        int R = L + 1;
        if(L < n){
            hash[L] = new TreeNode(nums[L]);
            hash[i]->left = hash[L];
        }
        if(R < n){
            hash[R] = new TreeNode(nums[R]);
            hash[i]->right = hash[R];
        }
        i++;
    }

    Solution solution;
    int targetSum;
    cin >> targetSum;
    vector<vector<int>> res = solution.pathSum(root, targetSum);
    
    for(auto v : res){
        for( int a : v){
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}