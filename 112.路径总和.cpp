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
    
    bool dfs(TreeNode* cur, int count){
        if(!cur->right && !cur->left && count == 0) return true;
        if(!cur->right && !cur->left) return false;

        if(cur->left){
            if(dfs(cur->left, count - cur->left->val)) return true;
        }
        if(cur->right){
            if(dfs(cur->right, count - cur->right->val)) return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return dfs(root, targetSum - root->val);
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
    cout << solution.hasPathSum(root, targetSum) << endl;
    
    
    return 0;
}