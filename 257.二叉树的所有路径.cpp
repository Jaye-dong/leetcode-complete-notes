#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    void traversal(TreeNode* cur, vector<int> &path, vector<string> &res){
        path.push_back(cur->val);
        if(cur->left == nullptr && cur->right == nullptr){
            /* convert to string */
            string sPath;
            for(int i = 0; i < (int)path.size() - 1; i++){
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            res.push_back(sPath);
            return;
        }

        if(cur->left){
            traversal(cur->left, path, res);
            /* backtracking */
            path.pop_back();
        }
        if(cur->right){
            traversal(cur->right, path, res);
            /* backtracking */
            path.pop_back();
        }
        return ;
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        traversal(root, path, res);
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
    vector<string> res = solution.binaryTreePaths(root);
    for(auto a : res)
        cout << a << endl;
    return 0;
}