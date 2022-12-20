#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        /* 第一步：判断终止条件 */
        if(root == nullptr || root->val == val) return root;
        /* 第二步：查找 */
        if(root->val > val) return searchBST(root->left, val);
        if(root->val < val) return searchBST(root->right, val);
        return nullptr;

    }
};


int main(){
    /* 注意，输入是二叉搜索树，否则可能会得到意想不到的结果 */
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int i = 0;
    unordered_map<int,TreeNode*> hash;
    hash[i] = new TreeNode(nums[i]);
    TreeNode * root = hash[i];

    while(i < n){
        int L = i * 2 + 1;
        int R = L + 1;
        if( L < n){
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
    int val;
    cin >> val;
    TreeNode * pRoot = solution.searchBST(root, val);
    
    queue<TreeNode*> q;
    
    if(pRoot){
        q.push(pRoot);
    }
    vector<vector<int>> res;

    while(!q.empty()){
        int size = q.size();
        vector<int> vec;
        for(int i = 0; i < size; i++){
            TreeNode * node = q.front();
            q.pop();
            vec.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res.push_back(vec);
    }
    
    for(auto v : res){
        for(auto a : v){
            cout << a << " ";
        }
        cout << endl;
    }
    return 0;
}