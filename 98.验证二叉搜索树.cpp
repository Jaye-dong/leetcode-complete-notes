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
    vector<TreeNode*> vecTree(vec.size(),nullptr);
    TreeNode *root = nullptr;
    for(int i = 0; i < vec.size(); i++){
        TreeNode*node = nullptr;
        if(vec[i] != -1) node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if(i == 0) root = node;
    }

    for(int i = 0; i * 2 + 2 < vec.size(); i++){
        if(vecTree[i] != nullptr){
            vecTree[i]->left = vecTree[i*2 + 1];
            vecTree[i]->right = vecTree[i*2 + 2];
        }
    }
    return root;
}

void print(TreeNode* root){
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
    for(auto v: res){
        for(int a : v){
            cout << a << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    TreeNode * pre = nullptr;
    bool isValidBST(TreeNode* root){
        if(root == nullptr) return true;
        /* 中序遍历 ， 确保中序遍历是严格从小到大 */
        bool left = isValidBST(root->left);

        if(pre && pre->val >= root->val) return false;
        /* 保存上一次的值 */
        pre = root;

        bool right = isValidBST(root->right);
        
        return left && right;
    }
};

int main(){
    // vector<int> vec{2,1,3,-1,-1, 4};
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    TreeNode * root = create(vec);
    Solution solution;
    cout << solution.isValidBST(root);
    return 0;
}