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
    
    ListNode* reversell(ListNode* head){
        if(!head or !head->next){
            return head;
        }
      ListNode* new_head=reversell(head->next);
      head->next->next=head;
      head->next=NULL;
      return new_head;
    } 

    bool isPalindrome(ListNode* head) {
        /* Brute force
               stack<int>st;
        ListNode* temp=head;
        while(temp){
            st.push(temp->val);
             temp=temp->next;
        }
        temp=head;
        while(temp){
            if(temp->val!=st.top()){
                return false;
            }
            temp=temp->next;
            st.pop();
        }
        return true;
        */
        if(!head or !head->next){
            return true;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next and fast->next->next ){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reversell(slow->next);
        ListNode* temp1=head;
        ListNode* temp2=newHead;
        while(temp2){
            if(temp1->val!=temp2->val){
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
};