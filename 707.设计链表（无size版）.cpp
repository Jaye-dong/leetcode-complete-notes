#include <iostream>

using namespace std;

class MyLinkedList
{

public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int _val) : val(_val), next(nullptr) {}
    };

    MyLinkedList()
    {
        _dummyHead = new ListNode(-1);
    }

    int get(int index)
    {
        ListNode *p = _dummyHead;
        int i = -1;
        while (p != nullptr)
        {
            p = p->next;
            i++;
            if (i == index && p != nullptr)
            {
                return p->val;
            }
        }
        return -1;
    }

    void addAtHead(int val)
    {
        ListNode *s = new ListNode(val);
        s->next = _dummyHead->next;
        _dummyHead->next = s;
    }

    void addAtTail(int val)
    {
        ListNode *s = new ListNode(val);
        ListNode *tail = _dummyHead;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = s;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0)
        {
            addAtHead(val);
            return;
        }
        ListNode *p = _dummyHead;
        ListNode *pre = nullptr;
        int i = -1;
        while (p != nullptr)
        {
            pre = p;
            p = p->next;
            i++;
            if (i == index)
            {
                ListNode *s = new ListNode(val);
                s->next = p;
                pre->next = s;
                break;
            }
        }
    }

    void deleteAtIndex(int index)
    {
        ListNode *pre, *p = _dummyHead;
        int i = -1;
        while (p != nullptr)
        {
            pre = p;
            p = p->next;
            i++;
            if (i == index && p != nullptr)
            {
                ListNode *temp = p;
                pre->next = p->next;
                p = p->next;
                delete (temp);
            }
        }
    }

private:
    ListNode *_dummyHead;
};

int main()
{
    MyLinkedList *linkList = new MyLinkedList();
    linkList->addAtIndex(1, 0);
    cout << linkList->get(1) << endl;
    return 0;
}