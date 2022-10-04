#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    int res;
    void getDepth(TreeNode * root, int depth){
        if(root->left == nullptr && root->right == nullptr){
            res =  min(depth, res);
            return;
        }
        if(root->left){
            getDepth(root->left, depth + 1);
        }
        if(root->right){
            getDepth(root->right, depth + 1);
        }
        return;
    }

    int minDepth(TreeNode * root){
        res = INT_MAX;
        if(root == nullptr) return 0;
        getDepth(root, 1);
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
    int res = solution.minDepth(root);
    cout << res << endl;
    return 0;
}