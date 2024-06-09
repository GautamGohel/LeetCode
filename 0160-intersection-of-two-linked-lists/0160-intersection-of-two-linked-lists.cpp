/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /* using hashmap
        map<ListNode*,int>mp;
        ListNode* temp1=headA;
        while(temp1){
            mp[temp1]=1;
            temp1=temp1->next;
        }
        ListNode* temp2=headB;
        while(temp2){
            if(mp.find(temp2)!=mp.end()){
                return temp2;
            }
            temp2=temp2->next;
        }
        return NULL;
        */
        /* by aligning head 
        int n1=0,n2=0;
        ListNode* temp1=headA;
        while(temp1){
            n1++;
            temp1=temp1->next;
        }
        ListNode* temp2=headB;
        while(temp2){
            n2++;
            temp2=temp2->next;
        }
        temp1=headA;
        temp2=headB;
        if(n2>n1){
          int d=n2-n1;
          while(d--){
            temp2=temp2->next;
          }
        }
        else{
           int d=n1-n2;
            while(d--){
                temp1=temp1->next;
            }
        }
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
        */
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==temp2) return temp1;
            if(!temp1) temp1=headB;
            if(!temp2) temp2=headA;
        }
        return temp1;
    }
};