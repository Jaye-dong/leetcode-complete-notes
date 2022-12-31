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
    for(int i = 0;i < vec.size(); i++){
        TreeNode * node = nullptr;
        if(vec[i] != -1 ) node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if(i == 0) root = node;
    }

    for(int i = 0; i < vec.size(); i++){
        if(vecTree[i] != nullptr){
            if(i * 2 + 1 < vec.size()) vecTree[i]->left = vecTree[i*2 + 1];
            if(i * 2 + 2 < vec.size()) vecTree[i]->right = vecTree[i*2 + 2];
        }
    }
    return root;
}


// TreeNode * create(const vector<int> &vec){
//     vector<TreeNode*> vecTree(vec.size(), nullptr);
//     TreeNode * root = nullptr;
//     for(int i = 0;i < vec.size(); i++){
//         TreeNode * node = nullptr;
//         if(vec[i] != -1 ) node = new TreeNode(vec[i]);
//         vecTree[i] = node;
//         if(i == 0) root = node;
//     }

//     for(int i = 0; i * 2 + 2 < vec.size();i++){
//         if(vecTree[i] != nullptr){
//             vecTree[i]->left = vecTree[i*2 + 1];
//             vecTree[i]->right = vecTree[i*2 + 2];
//         }
//     }
//     return root;
// }

class Solution{
public:
    int max_repeat = 0;
    int count = 0;
    vector<int> res;
    TreeNode * pre = nullptr;

    void dfs(TreeNode * root){
        if(root == nullptr) return;
        dfs(root->left);

        if(pre == nullptr){
            count = 1;
        }else if(pre->val == root->val){
            count++;
        }else{
            count = 1;
        }
        pre = root;

        if(count == max_repeat){
            res.push_back(root->val);
        }
        if(count > max_repeat){
            max_repeat = count;
            res.clear();
            res.push_back(root->val);
        }
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root){
        max_repeat = 0;
        count = 0;
        res.clear();
        TreeNode * pre = nullptr;
        dfs(root);
        return res;
    }
};

void print(TreeNode *root){
    if (!root) return;
    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> res;
    while (!q.empty()){
        int size = q.size();
        vector<int> vec;
        for (int i = 0; i < size; i++){
            TreeNode *node = q.front();
            q.pop();
            if (node){
                vec.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            else{
                vec.push_back(-1);
            }
        }
        res.push_back(vec);
    }
    for (auto v : res){
        for (int a : v){
            cout << a << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> vec{5,3,6,-1,-1,6};
    Solution solution;
    TreeNode * root = create(vec);
    print(root);
    vector<int> result = solution.findMode(root);
    for(auto a : result){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}