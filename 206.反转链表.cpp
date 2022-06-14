#include <iostream>
#include <vector>
struct ListNode{
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr){}
    ListNode(int _val, ListNode* _next) : val(_val), next(_next){}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head;
        ListNode *pre = nullptr;
        while(p != nullptr){
            ListNode * temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }
        return pre;
        
    }
};
int main(){
    ListNode *head = new ListNode();
    ListNode *p = head;
    std::vector<int> a{1,2,3,4,5};
    for(int i = 0; i < (int)a.size(); i++){
        ListNode *newNode = new ListNode(a[i]);
        p->next = newNode;
        p = p->next;
    }
    head = head->next;
    for(ListNode * q = head; q != nullptr; q = q->next){
        std::cout << q->val << ", ";
    }
    std::cout << std::endl;

    Solution solution;
    ListNode * res = solution.reverseList(head);
    for(ListNode * q = res; q != nullptr; q = q->next){
        std::cout << q->val << ", ";
    }
    std::cout << std::endl;
    return 0;
}