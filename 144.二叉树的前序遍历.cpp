#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};

class Solution{
public:
    void dfs(TreeNode *cur, vector<int> &res){
        if(cur == nullptr){
            return;
        }
        res.push_back(cur->val);
        dfs(cur->left, res);
        dfs(cur->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> res;
        dfs(root, res);
        return res;
    }
};

int main(){
    TreeNode *T = new TreeNode(1);
    T->left = new TreeNode(2);
    T->right = new TreeNode(3);
    Solution solution;
    vector<int> res = solution.preorderTraversal(T);
    for(int a : res){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}



