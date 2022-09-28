#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <stdio.h>

using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;
    Node * next;
    Node(){}
    Node(int x): val(x), left(nullptr), right(nullptr), next(nullptr){}
    Node(int x, Node* left_, Node* right_, Node* next_){
        val = x;
        left = left_;
        right = right_;
        next = next_;
    }
};

class Solution{
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root == nullptr) return root;
        q.push(root);
        int start = 1;
        while(!q.empty()){
            int size = q.size();
            vector<Node*> vec;
            for(int i = 0; i < size; i++){
                Node * node = q.front();
                q.pop();
                vec.push_back(node);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            int i;
            for(i = 0; i < (int)vec.size() - 1; i++){
                vec[i]->next = vec[i+1];
            }
            vec[i]->next = nullptr;
            {
                Node * p = vec[0];
                while(p != nullptr){
                    if(start){
                        cout << p->val;
                        start = 0;
                    }else{
                        cout << "," << p->val;
                    }
                    
                    p = p->next;
                }
                cout << ",#";
            }
        }
        return root;
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
    unordered_map<int, Node*> hash;
    Node * root;
    while(i < n){
        if(i == 0){
            hash[i] = new Node(nums[i]);
            root = hash[i];
        }
        if(i*2+1 < n){
            hash[i*2+1]  = new Node(nums[i*2+1]);
            hash[i]->left = hash[i*2+1];
       }
        if(i*2+2 < n){
            hash[i*2+2] = new Node(nums[i*2+2]);
            hash[i]->right = hash[i*2+2];
        }
        i++;
    }

    Solution solution;
    root = solution.connect(root);
    
    return 0;    
}
