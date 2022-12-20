#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
};

class Solution{
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        /* 第一步：判空 */
        if( root1 == nullptr ) return root2;
        if( root2 == nullptr ) return root1;
        
        /* 第二步：遍历 中左右 */
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};


int main(){
    int treeCount = 2;
    TreeNode* roots[2];
    int k = 0;
    while(k < treeCount){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }
        
        int i = 0;
        unordered_map<int,TreeNode*> hash;
        hash[i] = new TreeNode(nums[i]);
        roots[k] = hash[i];
        while(i < n){
            int L = i*2 + 1;
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
        k++;
    }

    Solution solution;
    TreeNode *pRoot = solution.mergeTrees(roots[0], roots[1]);
    vector<vector<int>> res;
    queue<TreeNode*> q;
    if(pRoot) q.push(pRoot);
    while(!q.empty()){
        
        int size = q.size();
        vector<int> vec;
        for(int i = 0; i < size; i++){
            TreeNode * node = q.front();
            q.pop();
            vec.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        res.push_back(vec);
    }
    

    for(auto v : res){
        for( auto a : v){
            cout << a << " ";
        }
        cout << endl;
    }



    

    return 0;
}