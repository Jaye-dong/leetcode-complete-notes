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

class Solution{
public:
    void dfs(TreeNode * cur, vector<int> &res){
        if(cur == nullptr) return;
        dfs(cur->left, res);
        dfs(cur->right, res);
        res.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode * root){
        vector<int> res;
        dfs(root, res);
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
    TreeNode *root = nullptr;
    while(i < (int)nums.size()){
        if(i == 0){
            hash[i] = new TreeNode(nums[i]);
            root = hash[i];
        }
        TreeNode *T = hash[i];
        if(i*2+1 < (int)nums.size()){
            TreeNode *Node = new TreeNode(nums[i*2+1]);
            T->left = Node;
            hash[i*2+1] = T->left;
        }
        if(i*2+2 < (int)nums.size()){
            TreeNode *Node = new TreeNode(nums[i*2+2]);
            T->right = Node;
            hash[i*2+2] = T->right;
        }
        i++;
    }
    
    Solution solution;
    vector<int> res = solution.postorderTraversal(root);
    for(int a : res){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}