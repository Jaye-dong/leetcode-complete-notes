#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == NULL && right != NULL) return false;
        else if (left != NULL && right == NULL) return false;
        else if (left == NULL && right == NULL) return true;
        else if (left->val != right->val) return false;
        else return compare(left->left, right->left) && compare(left->right, right->right);

    }
    void traversal(TreeNode* cur, TreeNode* subRoot, bool &res){
        if(cur == nullptr) return ;
        if(compare(cur, subRoot)){
            res = true;
        }
        traversal(cur->left, subRoot, res);
        traversal(cur->right, subRoot, res);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool res = false;
        traversal(root, subRoot, res);
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
    hash[i] = new TreeNode(nums[i]);
    TreeNode * root = hash[i];
    while(i < n){
        int L = i * 2 + 1;
        int R = L + 1;
        if(L < n){
            hash[L] = new TreeNode(nums[L]);
            hash[i]->left = hash[L];
        }
        if(R < n){
            hash[R] = new TreeNode(nums[R]);
            hash[i]->right = hash[R];
        }
        i++;
    }

    int m;
    cin >> m;
    vector<int> nums2(m);
    for(int i = 0; i < m; i++){
        cin >> nums2[i];
    }
    i = 0;
    unordered_map<int, TreeNode*> hash2;
    hash2[i] = new TreeNode(nums2[i]);
    TreeNode * root2 = hash2[i];
    while(i < m){
        int L = i * 2 + 1;
        int R = L + 1;
        if(L < m){
            hash2[L] = new TreeNode(nums2[L]);
            hash2[i]->left = hash2[L];
        }
        if(R < m){
            hash2[R] = new TreeNode(nums2[R]);
            hash2[i]->right = hash2[R];
        }
        i++;
    }

    Solution solution;
    bool res = solution.isSubtree(root, root2);

    cout << res << endl;
    return 0;
}