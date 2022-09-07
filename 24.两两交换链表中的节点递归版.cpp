#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int _val):val(_val){}
};
class Solution{

public:
    ListNode* swapPairs(ListNode* head){
        if( !head || !head->next){
            return head;
        }
        ListNode * newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};

int main(){
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for(int i = 1; i < 20; i++){
        ListNode * s = new ListNode(i);
        p->next = s;
        p = p->next;
    }
    Solution solution;
    p = solution.swapPairs(head);
    while(p){
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}