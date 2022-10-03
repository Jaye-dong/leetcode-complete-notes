#include <iostream>
#include <queue>
#include <vector>
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
    int minDepth(TreeNode * root){
        int res = 0;
        queue<TreeNode*> q;
        if(root == nullptr) return res;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            res++;
            for(int i = 0; i < size; i++){
                TreeNode * node = q.front();
                q.pop();
                /* if encounter a leaf node return the current depth */ 
                if(node->left == nullptr && node->right == nullptr) return res;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i= 0; i < n; i++){
        cin >> nums[i];
    }
    int i = 0;
    unordered_map<int, TreeNode*> hash;
    TreeNode * root;
    while(i < n){
        if(i == 0){
            hash[i] = new TreeNode(nums[i]);
            root = hash[i];
        }
        if(i*2+1 < n){
            hash[i*2+1] = new TreeNode(nums[i*2+1]);
            hash[i]->left = hash[i*2+1];
        }
        if(i*2+2 < n){
            hash[i*2 + 2] = new TreeNode(nums[i*2+2]);
            hash[i]->right = hash[i*2+2];
        }
        i++;
    }
    Solution solution;
    int res = solution.minDepth(root);
    cout << res << endl;
    return 0;
}