#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
    int val;
    vector<Node*> children;

    Node(){}

    Node(int x): val(x){}

    Node(int x, vector<Node*> _children){
        val = x;
        children = _children;
    }
};

class Solution{
public:
    void dfs(Node* root, vector<int> &vec){
        if(root == nullptr) return;
        for(int i = 0; i < (int)root->children.size(); i++){
            dfs(root->children[i], vec);
        }
        vec.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        dfs(root, res);
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
    queue<Node*> q;
    Node * root = new Node(nums[i++]);
    Node * pNode;
    q.push(root);
    while(i < n){
        if(nums[i] == -1){
            pNode = q.front();
            q.pop();
            i++;
            continue;
        }
        Node * node = new Node(nums[i++]);
        q.push(node);
        pNode->children.push_back(node);
    }

    Solution solution;
    vector<int> res = solution.postorder(root);
    for(int a : res){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}