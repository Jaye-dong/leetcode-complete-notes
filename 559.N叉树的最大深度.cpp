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
    int getDepth(Node* root){
        if(root == nullptr) return 0;
        int maxChildDepth = 0;
        for(int i =0; i < (int)root->children.size(); i++){
            maxChildDepth = max(maxChildDepth, getDepth(root->children[i]));
        }
        return maxChildDepth + 1;
    }
    int maxDepth(Node* root) {
        return getDepth(root);
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
    Node* root = new Node(nums[i++]);
    queue<Node*> q;
    q.push(root);
    Node* pNode;
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
    int res = solution.getDepth(root);
    cout << res << endl;
    return 0;
}