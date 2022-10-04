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

class Solution{
public:
    bool compare(TreeNode * leftNode, TreeNode * rightNode){
        if(leftNode == nullptr && rightNode == nullptr){
            return true;
        }
        if(!leftNode || !rightNode || (leftNode->val != rightNode->val)){
            return false;
        }

        bool sLeft = compare(leftNode->left, rightNode->left);
        bool sRight = compare(leftNode->right, rightNode->right);
        bool isSame = sLeft && sRight;
        return isSame;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p, q);
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
    while(i < n){
        int L = i * 2 + 1;
        int R = L + 1;
        if(L < n){
            hash2[L] = new TreeNode(nums2[L]);
            hash2[i]->left = hash2[L];
        }
        if(R < n){
            hash2[R] = new TreeNode(nums2[R]);
            hash2[i]->right = hash2[R];
        }
        i++;
    }

    Solution solution;
    bool res = solution.isSameTree(root, root2);

    cout << res << endl;
    return 0;
}