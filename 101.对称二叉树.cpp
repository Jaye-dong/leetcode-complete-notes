#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    bool isSymmetric(TreeNode* root) {
        bool res = true;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode * leftNode = q.front(); q.pop();
            TreeNode * rightNode = q.front(); q.pop();
            if(!leftNode && !rightNode){
                continue;
            }
            if(!leftNode || !rightNode || (leftNode->val != rightNode->val)){
                return false;
            }
            /* outside */
            q.push(leftNode->left);
            q.push(rightNode->right);
            /* inside */
            q.push(leftNode->right);
            q.push(rightNode->left);
        }
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

    Solution solution;
    bool res = solution.isSymmetric(root);
    cout << res << endl;
    return 0;
}