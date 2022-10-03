#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode * node = st.top();
            st.pop();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
            swap(node->left, node->right);
        }
        return root;
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
    TreeNode* res = solution.invertTree(root);
    queue<TreeNode*> q;
    
    if(root) q.push(res);
    while(!q.empty()){
        int size = q.size();
        int start = 1;
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(start){
                start = 0;
                cout << node->val;
            }else {
                cout << "," << node->val;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << endl;
    }
    return 0;
}