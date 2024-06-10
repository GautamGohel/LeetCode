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

    ListNode* lastNode(ListNode* temp,int k){
       int cnt=0;
       while(temp){
        cnt++;
        if(cnt==k) return temp;
        temp=temp->next;
       }
       return temp;
    }
   
    ListNode* rotateRight(ListNode* head, int k) {
      if(!head or !head->next){
        return head;
      }  
      ListNode* tail=head;
      int len=1;
      while(tail->next){
         len++;
         tail=tail->next;
      }
      k=k%len;
      if(k==0){
        return head;
      }
      tail->next=head;
      ListNode* lastnode=lastNode(head,len-k);
       head=lastnode->next;
      lastnode->next=NULL;
      return head;
    }
};