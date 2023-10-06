#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0, sum = 0;
    ListNode* head = NULL;
    ListNode* itr = NULL;
    do {
        sum = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        ListNode* node = new ListNode(sum);
        if (!head) {
            head = itr = node;
        } else {
            itr->next = node;
            itr = itr->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    } while (l1 && l2);
    while (l1) {
        sum = (l1->val + carry) % 10;
        carry = (l1->val + carry) / 10;
        ListNode* node = new ListNode(sum);
        itr->next = node;
        itr = itr->next;
        l1 = l1->next;
    }
    while (l2) {
        sum = (l2->val + carry) % 10;
        carry = (l2->val + carry) / 10;
        ListNode* node = new ListNode(sum);
        itr->next = node;
        itr = itr->next;
        l2 = l2->next; 
    }
    if (carry) {        itr->next = new ListNode(carry);        }
    return head;
}
