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
    int countNodes(TreeNode * root){
        if(root == nullptr) return 0;
        /* judge the tree whether a full binary tree or not */
        TreeNode * leftNode = root->left;
        TreeNode * rightNode = root->right;
        int leftDepth = 0;
        int rightDepth = 0;
        while(leftNode){
            leftNode = leftNode->left;
            leftDepth++;
        }
        while(rightDepth){
            rightNode = rightNode->right;
            rightDepth++;
        }
        if(leftDepth == rightDepth){
            return (2 << leftDepth) - 1;
        }
        int leftNodesNum = countNodes(root->left);
        int rightNodesNum = countNodes(root->right);
        int TreeNum = 1 + leftNodesNum + rightNodesNum;
        return TreeNum;
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
    int res = solution.countNodes(root);
    cout << res << endl;
    return 0;
}