#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode * right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};
using namespace std;

class Solution{
public:

    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> st;
        if(root == nullptr) return res;
        st.push(root);
        while(!st.empty()){
            TreeNode * node = st.top();
            if(node != nullptr){
                st.pop();
                if(node->right){
                    st.push(node->right);
                }
                if(node->left){
                    st.push(node->left);
                }
                st.push(node);
                st.push(nullptr);
                
            }else{
                st.pop();
                TreeNode *node = st.top();
                st.pop();
                res.push_back(node->val);
            }
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
            hash[i*2+1] = new TreeNode(nums[i*2+1]);
            hash[i]->left = hash[i*2+1];
        }
        if(i*2+2 < n){
            hash[i*2+2] = new TreeNode(nums[i*2+2]);
            hash[i]->right = hash[i*2+2];
        }
        i++;
    }

    Solution solution;
    vector<int> res = solution.inorderTraversal(root);
    for(int a : res){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}