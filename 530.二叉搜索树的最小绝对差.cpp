#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};


TreeNode* create(const vector<int> &vec){
    vector<TreeNode*> vecTree(vec.size(), nullptr);
    TreeNode * root = nullptr;
    for(int i = 0; i < vec.size(); i++){
        TreeNode* node = nullptr;
        if(vec[i] != -1) node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if(i == 0) root = node;
    }

    for(int i = 0; i*2+2 < vec.size(); i++){
        if(vecTree[i]){
            vecTree[i]->left = vecTree[i*2+1];
            vecTree[i]->right = vecTree[i*2+2];
        }
    }
    return root;
}

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

class Solution{
public:

    int min_gap = INT_MAX;
    /* 存上一个结点 */
    TreeNode * pre = nullptr;
    void dfs(TreeNode * root){
        if(root == nullptr) return;
        /* 中序遍历，二叉搜索树按中序是从小到大的 */
        dfs(root->left);
        if(pre){
            min_gap = min(min_gap, root->val - pre->val);
        }
        /* 保持上一个结点 */
        pre = root;
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root){
        dfs(root);
        return min_gap;
    }
};

int main(){

    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    TreeNode * root = create(vec);
    print(root);
    Solution solution;
    cout << solution.getMinimumDifference(root);
    return 0;
}