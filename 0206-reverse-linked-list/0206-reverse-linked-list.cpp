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
        /* iterative
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr){
            ListNode* nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
        }
        return prev;
        */
        //recursive
      if(!head or !head->next){
          return head;
      }
      ListNode* newHead=reverseList(head->next);
      ListNode* front=head->next;
      front->next=head;
      head->next=NULL;
      return newHead;
    }
};