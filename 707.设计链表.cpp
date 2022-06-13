#include <iostream>

using namespace std;
class MyLinkedList {
public:
    struct ListNode{
        int val;
        struct ListNode * next;
        ListNode(int _val) : val(_val), next(nullptr) {}

    };
    MyLinkedList() {
        _dummyHead = new ListNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index >= _size || index < 0){
            return -1;
        }
        ListNode * p = _dummyHead->next;
        while(index--){
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        ListNode * newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode * newNode = new ListNode(val);
        ListNode * p = _dummyHead;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        ListNode * newNode = new ListNode(val);
        if(index > _size || index < 0){
            return;
        }
        ListNode * p = _dummyHead->next;
        ListNode * pre = _dummyHead;
        while(index--){
            pre = p;
            p = p->next;
        }
        pre->next = newNode;
        newNode->next = p;
        _size++;
        return;
    }
    
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0){
            return;
        }
        ListNode * p = _dummyHead->next;
        ListNode * pre = _dummyHead;
        while(index--){
            pre = p;
            p = p->next;
        }
        pre->next = p->next;
        
        delete p;
        _size--;
        return;
    }
private:
    int _size;
    ListNode *_dummyHead;
};

int main(){
    MyLinkedList* a = new MyLinkedList();
    int index = 1;
    a->addAtHead(1);
    a->addAtTail(2);
    a->deleteAtIndex(index);
    a->addAtIndex(1, 3);
    int param_1 = a->get(index);
    
    cout << param_1 << endl;
    
    return 0;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */