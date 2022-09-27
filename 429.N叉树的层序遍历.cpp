#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
    int val;
    vector<Node*> children;

    Node(){}

    Node(int x): val(x) {}

    Node(int val_, vector<Node*> children_){
        val = val_;
        children = children_;
    }
};
class Solution{
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;
        if(root == nullptr) return res;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> vec;
            for(int i = 0; i < size; i++){
                Node * node = q.front();
                q.pop();
                vec.push_back(node->val);
                for(int j = 0;j < (int)node->children.size(); j++){
                    q.push(node->children[j]);
                }
            }
            res.push_back(vec);
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
    queue<Node*> q;
    Node * root;
    Node * pNode;
    int i = 0;
    Node * node = new Node(nums[i++]);
    root = node;
    q.push(root);
    while(i < n){
        if(nums[i] == -1){ 
            pNode = q.front();
            q.pop();
            i++;
            continue;
        }
        Node * node = new Node(nums[i]);
        q.push(node);
        pNode->children.push_back(node);
        i++;
    }
    
    Solution solution;
    vector<vector<int>> res = solution.levelOrder(root);
    
    for(auto v : res){
        for(int a : v){
            cout << a << " ";
        }
        cout << endl;
    }
    
    return 0;
}