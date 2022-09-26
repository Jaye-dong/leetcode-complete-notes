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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root == nullptr) return res;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int last;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                last = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(last);
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
    TreeNode * root;
    while(i < n){
        if(i == 0){
            hash[i] = new TreeNode(nums[i]);
            root = hash[i];
        }
        if(i*2+1 < n){
            if(nums[i*2+2] != -1){
                hash[i*2+1] = new TreeNode(nums[i*2+1]);
                hash[i]->left = hash[i*2+1];
            }
        }
        if(i*2+2 < n){
            if(nums[i*2+2] != -1){
                hash[i*2+2] = new TreeNode(nums[i*2+2]);
                hash[i]->right = hash[i*2+2];
            }

        }
        i++;
    }
    Solution solution;
    vector<int> res = solution.rightSideView(root);
    for(int a : res){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}