#include <vector>
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode *_next) : val(_val), next(_next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode * cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr){
            ListNode * tmp = cur->next;
            ListNode * tmp1 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp1;
            cur = cur->next->next; 
        }
        return dummyHead->next;
        
    }
};

int main(){
    ListNode *head = new ListNode();
    vector<int> a = {1,2,3,4};
    ListNode * p = head;
    for(int i = 0; i < (int)a.size(); i++){
        ListNode * newNode = new ListNode(a[i]);
        p->next = newNode;
        p = p->next;
    }
    head = head->next;

    for(ListNode * q = head; q != nullptr; q = q->next){
        cout << q->val << ", ";
    }
    cout << endl;

    Solution solution;
    ListNode * res = solution.swapPairs(head);

    for(ListNode * q = res; q != nullptr; q = q->next){
        cout << q->val << ", ";
    }
    cout << endl;
    return 0;
}