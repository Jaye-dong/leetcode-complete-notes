#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int _val): val(_val), next(nullptr){}
};
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode * newHead = new ListNode(-1);
        ListNode * slow = newHead;
        slow->next = head;
        ListNode * fast = head;
        int sIndex = -1;
        int fIndex = 0;
        while(fast != nullptr){
            fast = fast->next;
            fIndex++;
            if(fIndex - sIndex > n+1){
                slow = slow->next;
                sIndex++;
            }
        }
        ListNode * temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        
        
        return newHead->next;
    }
};

int main(){
    ListNode * head = new ListNode(0);
    ListNode * p = head;
    for(int i = 1; i < 10; i++){
        ListNode* s = new ListNode(i);
        p->next = s;
        p = p->next;
    }
    Solution solution;
    p = solution.removeNthFromEnd(head, 1);
    for(int i = 0; i < 10; i++){
        cout << p->val << endl;
        p = p->next;
    }
    
    return 0;
}