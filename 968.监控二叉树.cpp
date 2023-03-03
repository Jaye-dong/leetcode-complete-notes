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
        /* 0 �� �޸���
         * 1 �� ����ͷ
         * 2 �� �и���
        */
        /* Ҷ�ӽ��Ҫ�������и��ǣ�����ͻ�����������Ҷ�ӽ������ */
        if(root == nullptr){
            return 2;
        }
        /* ������� */
        int left = traversal(root->left);
        int right = traversal(root->right);

        /* ����������Ӷ��и��ǣ���ǰ����޸��� */
        if (left == 2 && right == 2) {
            return 0;
        }

        /* �������������һ���޸��ǣ���ǰ�����Ҫ����һ������ͷ */
        if ( left == 0 || right == 0){
            result++;
            return 1;
        }

        /* ���������������һ������ͷ����ǰ�����Ϊ�и��� */
        if (left == 1 || right == 1){
            return 2;
        }
        /* �����ܵ����߼� */
        return -1;
    }
    int minCameraCover(TreeNode* root){
        result = 0;
        /* ��������ڵ����޸��ǣ�����һ������ͷ�����ڵ� */
        if(traversal(root) == 0){
            result++;
        }
        return result;
    }
};

// �������鹹�������
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

// �����ӡ��ӡ������
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
            // ����Ĵ����߼���Ϊ�˰�null�ڵ��ӡ��������-1 ��ʾnull
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