#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MyLinkedList {
public:
    ListNode* vhead;
    ListNode* tail;
    int len;
    MyLinkedList() { vhead = new ListNode(); len = 0; tail = vhead; }
    MyLinkedList(ListNode* h)
    {
        vhead = new ListNode(); vhead->next = h;
        len = 0; ListNode* i = h;
        while (i != nullptr) { len++; tail = i; i = i->next;}
    }

    ListNode* getpointer(int index)
    {
        if (index < len && index > 0)
        {
            ListNode* p = vhead->next;
            while (index - 1 > 0)
            {
                p = p->next;
                index--;
            }
            return p;
        }
        else if(index == 0)
        {
            return vhead;
        }
        else
        {
            return nullptr;
        }
    }

    int get(int index) {
        ListNode* p = this->getpointer(index);
        if (p == nullptr || vhead == tail) { return -1; }
        else { return p->next->val; }
    }

    void addAtHead(int val) {
        ListNode* a = new ListNode(val, vhead->next);
        this->vhead->next = a;
        this->len++;
        if (a->next == nullptr) { tail = a; }
    }

    void addAtTail(int val) {
        ListNode* a = new ListNode(val);
        tail->next = a;
        tail = a;
        this->len++;
    }

    void addAtIndex(int index, int val) {
         if (index == 0)
        {
            this->addAtHead(val);
        }
        else if( index > 0 && index < len)
        {
            ListNode* p = this->getpointer(index);
                ListNode* a = new ListNode(val);
                a->next = p->next;
                p->next = a;
                this->len++;
            
        }
        else if (index == len) { addAtTail(val); }
        else { return; }
    }
        void deleteAtIndex(int index) 
        {
            if (index >= 0 && index < len)
            {
                ListNode* p = this->getpointer(index);
                ListNode* q = p->next;
                if (q == tail)
                {
                    ListNode *q = p->next;
                    tail = p;
                    delete q; q = nullptr;
                    this->len--;
                }
                else 
                {
                    p->next = q->next;
                    delete q; q = nullptr;
                    this->len--;
                }
            }
            else { return; }
            
            
        }
        void show()
        {
            cout << this->tail->val << endl;
        }
};

int main()
{
    MyLinkedList *myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->addAtTail(3);
    myLinkedList->addAtIndex(1, 2);
    cout << myLinkedList->get(1) << endl;
    myLinkedList->deleteAtIndex(1);
    cout << myLinkedList->get(1) << endl;
    cout << myLinkedList->get(3) << endl;
    myLinkedList->deleteAtIndex(3);
    myLinkedList->deleteAtIndex(0);
    cout << myLinkedList->get(0) << endl;
    myLinkedList->deleteAtIndex(0);
    cout << myLinkedList->get(0) << endl;
    
}