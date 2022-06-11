#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode * next;
    
    ListNode(int _val) : val(_val) , next(nullptr){}
    ListNode(int _val, struct ListNode * _head) : val(_val) , next(_head){}
    
};

void InsertElement(ListNode *tail, int val){
    ListNode * s = new ListNode(val);
    tail->next = s;
}

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode * newhead = new ListNode(0, head);
        ListNode * p = head;
        ListNode * pre = newhead;
        while(p != nullptr){
            if(p->val == val){  
                ListNode * temp = p;
                pre->next = p->next;
                p = p->next;
                delete temp;
            }else{
                pre = p;
                p = p->next;
            }
        }
        head = newhead->next;
        delete newhead;
        return head;
        
    }
};

int main(){
    Solution solution;
    vector<int> a = {1,2,6,3,4,5,6};
    ListNode * head = new ListNode(a[0], nullptr);
    ListNode * tail = head;
    for(int i = 1; i < (int)a.size() ; i++){
        InsertElement(tail, a[i]);
        tail = tail->next;
    }
    
    cout << "original :" << endl;
    for(ListNode* p = head; p != nullptr; p = p->next ){
        if(p == head){
            cout << p->val;
        }else{
            cout << "->" << p->val;
        }
        
    }
    cout << endl;
    
    
    head = solution.removeElements(head, 6);
    cout << "new :" << endl;
    for(ListNode* p = head; p != nullptr; p = p->next ){
        if(p == head){
            cout << p->val;
        }else{
            cout << "->" << p->val;
        }
    }
    return 0;
}

