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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* L = new ListNode(0, head);
        if (L->next == nullptr) { return nullptr; }
        else if (L->next->next == nullptr) { return head; }
        else{
            
            ListNode* p = head;
            ListNode* q = head->next;
            ListNode* rTag = q->next;
            ListNode* lTag = L;
            q->next = p;
            L->next = q;
            while ( rTag!= nullptr)
            {
                lTag = lTag->next->next;
                lTag->next = rTag;
                p = rTag;
                q = rTag->next;
                if (q != nullptr)
                {
                    lTag->next = q;
                    rTag = q->next;
                    q->next = p;
                }
                else
                {
                    lTag->next = rTag;
                    ListNode* l = L->next;
                    delete L; L = nullptr;
                    return l;
                }  
            }
            lTag = lTag->next->next;
            lTag->next = rTag;
            return L->next;
        }
    }
};

int main()
{
    ListNode* l6 = new ListNode(6);
    ListNode* l5 = new ListNode(5,l6);
    ListNode* l4 = new ListNode(4, l5);
    ListNode* l3 = new ListNode(3);
    ListNode* l2 = new ListNode(2, l3);
    ListNode* l1 = new ListNode(1, l2);
    ListNode* head = new ListNode(0, l1);
    Solution s;
    ListNode* h = s.swapPairs(l1);
    ListNode* p = h;
    while (p != nullptr) { cout << p->val << " "; p = p->next; }
}