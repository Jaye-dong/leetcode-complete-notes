#include <iostream>
#include <vector>
#include <queue>
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
    bool compare(TreeNode* leftNode, TreeNode* rightNode){
        /* exclude null situation */
        if(!leftNode && !rightNode) return true;
        if(!leftNode || !rightNode || (leftNode->val != rightNode->val)){
            return false;
        }
        bool outside = compare(leftNode->left, rightNode->right);
        bool inside = compare(leftNode->right, rightNode->left);
        bool isSame = outside && inside;
        return isSame;
    }
    bool isSymmetric(TreeNode* root) {
        bool res = compare(root->left, root->right);
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
    bool res = solution.isSymmetric(root);
    cout << res << endl;
    return 0;
}