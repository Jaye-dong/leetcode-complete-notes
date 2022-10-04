#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution{
public:
    bool isSymmetric(TreeNode* root) {
        bool res = true;
        stack<TreeNode*> st;
        if(root == nullptr) return res;
        st.push(root->left);
        st.push(root->right);
        while(!st.empty()){
            TreeNode * leftNode = st.top(); st.pop();
            TreeNode * rightNode = st.top(); st.pop();

            if(!leftNode && !rightNode){
                continue;
            }
            if(!leftNode || !rightNode || (leftNode->val != rightNode->val)){
                return false;
            }
            st.push(leftNode->left);
            st.push(rightNode->right);
            st.push(leftNode->right);
            st.push(rightNode->left);
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