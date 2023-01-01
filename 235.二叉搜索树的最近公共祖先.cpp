#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};

TreeNode * create(const vector<int> &vec){
    vector<TreeNode*> vecTree(vec.size(), nullptr);
    TreeNode * root = nullptr;
    
    for(int i = 0; i < vec.size(); i++){
        TreeNode * node = nullptr;
        if(vec[i] != -1) node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if(i == 0) root = node;
    }

    for(int i = 0; i < vec.size(); i++){
        if(vecTree[i]){
            if(i*2 + 1 < vec.size()) vecTree[i]->left = vecTree[i*2 + 1];
            if(i*2 + 2 < vec.size()) vecTree[i]->right = vecTree[i*2 + 2];
        }
    }
    return root;
}


void print(TreeNode * root){
    if(root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> res;
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
        for(auto a : v){
            cout << a << " ";
        }
        cout << endl;
    }
}

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};


int main(){
    vector<int> vec{2,1,3,-1,-1,6};
    print(create(vec));
    TreeNode * root = create(vec);
    Solution solution;
    cout << solution.lowestCommonAncestor(root, root->right, root->right->left)->val;
    return 0;
}