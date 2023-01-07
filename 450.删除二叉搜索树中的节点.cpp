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
            if(i*2+1 < vec.size()) vecTree[i]->left = vecTree[i*2+1];
            if(i*2+2 < vec.size()) vecTree[i]->right = vecTree[i*2+2];
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }else if(root->left == nullptr && root->right != nullptr){
                TreeNode * retNode = root->right;
                delete root;
                return retNode;
            }else if(root->left != nullptr && root->right == nullptr){
                TreeNode * retNode = root->left;
                delete root;
                return retNode;
            }else{
                /* 把删除结点的左子树放在右子树的最左边 */
                TreeNode * right = root->right;
                while(right->left){
                    right = right->left;
                }
                right->left = root->left;
                TreeNode * tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
        }

        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};


int main(){
    vector<int> vec{5, 3, 6, 2, 4, -1, 7};
    TreeNode * root = create(vec);
    print(root);
    Solution solu;
    root = solu.deleteNode(root, 3);
    print(root);
    return 0;
}