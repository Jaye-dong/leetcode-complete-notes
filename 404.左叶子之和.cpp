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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 0;
        int sum = 0;
        int leftNodes = sumOfLeftLeaves(root->left);
        if(root->left && root->left->left == nullptr && root->left->right == nullptr){
            leftNodes = root->left->val;
        }
        int rightNodes = sumOfLeftLeaves(root->right);
        sum += leftNodes + rightNodes;
        return sum;
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
    int res = solution.sumOfLeftLeaves(root);
    cout << res << endl;
    return 0;
}