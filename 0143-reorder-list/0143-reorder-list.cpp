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
    void reorderList(ListNode* head) {
    
         ListNode *slow = head;
    ListNode *fast = head;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 2.reverse second part of linkedlist
    ListNode *currptr = slow->next;
    ListNode *prevptr = slow;
    slow->next = NULL;
    while (currptr)
    {
        ListNode *nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    ListNode *head1 = head;
    ListNode *head2 = prevptr;
    // make new orders
    while (head1 != head2)
    {
        ListNode *temp = head1->next;
        head1->next = head2;
        head1 = head2;
        head2 = temp;
    }
    }
};