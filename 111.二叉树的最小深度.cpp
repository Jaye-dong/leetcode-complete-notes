#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    int getDepth(TreeNode * root){
        if(root == nullptr) return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        
        if(root->left == nullptr && root->right != nullptr){
            return 1 + rightDepth;
        }
        if(root->right == nullptr && root->left != nullptr){
            return 1 + leftDepth;
        }
        return 1 + min(leftDepth, rightDepth);
    }

    int minDepth(TreeNode * root){
        return getDepth(root);
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
    TreeNode * root = hash[i];
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
    int res = solution.minDepth(root);
    cout << res << endl;
    return 0;
}