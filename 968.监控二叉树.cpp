#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode{
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {} 
};



class Solution {
public:
    int result = 0;
    int traversal(TreeNode* root){
        /* 0 ： 无覆盖
         * 1 ： 摄像头
         * 2 ： 有覆盖
        */
        /* 叶子结点要当成是有覆盖，否则就会把摄像机放在叶子结点上了 */
        if(root == nullptr){
            return 2;
        }
        /* 后序遍历 */
        int left = traversal(root->left);
        int right = traversal(root->right);

        /* 如果两个孩子都有覆盖，则当前结点无覆盖 */
        if (left == 2 && right == 2) {
            return 0;
        }

        /* 如果两个孩子有一个无覆盖，当前结点需要放置一个摄像头 */
        if ( left == 0 || right == 0){
            result++;
            return 1;
        }

        /* 如果两个孩子中有一个摄像头，当前结点置为有覆盖 */
        if (left == 1 || right == 1){
            return 2;
        }
        /* 不会跑到的逻辑 */
        return -1;
    }
    int minCameraCover(TreeNode* root){
        result = 0;
        /* 如果到根节点了无覆盖，放置一个摄像头到根节点 */
        if(traversal(root) == 0){
            result++;
        }
        return result;
    }
};

// 根据数组构造二叉树
TreeNode* construct_binary_tree(const vector<int>& vec) {
    vector<TreeNode*> vecTree (vec.size(), NULL);
    TreeNode* root = NULL;
    for (int i = 0; i < vec.size(); i++) {
        TreeNode* node = NULL;
        if (vec[i] != -1) node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    for (int i = 0; i * 2 + 1 < vec.size(); i++) {
        if (vecTree[i] != NULL) {
            vecTree[i]->left = vecTree[i * 2 + 1];
            if(i * 2 + 2 < vec.size())
            vecTree[i]->right = vecTree[i * 2 + 2];
        }
    }
    return root;
}

// 层序打印打印二叉树
void print_binary_tree(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (node != NULL) {
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            }
            // 这里的处理逻辑是为了把null节点打印出来，用-1 表示null
            else vec.push_back(-1);
        }
        result.push_back(vec);
    }
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    TreeNode* root = construct_binary_tree(nums);
    print_binary_tree(root);
    cout << Solution().minCameraCover(root) << endl;
    return 0;
}