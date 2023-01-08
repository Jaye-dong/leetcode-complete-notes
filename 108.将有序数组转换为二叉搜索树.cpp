#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};

TreeNode * create(const vector<int> &vec){
    vector<TreeNode*> vecTree(vec.size(), nullptr);
    TreeNode* root = nullptr;
    for(int i = 0; i < vec.size(); i++){
        TreeNode * node = nullptr;
        if(vec[i] != -1) node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if(i == 0) root = node;
    }
    for(int i = 0; i < vec.size(); i++){
        if(vecTree[i]){
            if(i*2+1 < vec.size()){
                vecTree[i]->left = vecTree[i*2+1];
            }
            if(i*2+2 < vec.size()){
                vecTree[i]->right = vecTree[i*2+2];
            }
        }
    }

    return root;
}

void print(TreeNode * root){
    if(root == nullptr) return;
    queue<TreeNode*> q;
    vector<vector<int>> res;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> vec;
        for(int i = 0; i < size; i++){
            TreeNode * node = q.front();
            q.pop();
            if(node){
                vec.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }else{
                vec.push_back(-1);
            }
        }
        res.push_back(vec);
    }
    for(auto v : res){
        for(int a : v){
            cout << a << " ";
        }
        cout << endl;
    }
}

class Solution{
public:
    TreeNode * traversal(vector<int> & nums, int left, int right){
        if(left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode * root = new TreeNode(nums[mid]);
        
        root->left = traversal(nums, left, mid - 1);
        root->right = traversal(nums, mid + 1, right);
        return root;
    }
    TreeNode * sortedArrayToBST(vector<int>& nums){
        return traversal(nums, 0, nums.size() - 1);
    }
};
int main(){
    vector<int> vec{-10,-3,0,5,9};
    Solution solution;
    TreeNode * root = solution.sortedArrayToBST(vec);
    print(root);
    return 0;
}