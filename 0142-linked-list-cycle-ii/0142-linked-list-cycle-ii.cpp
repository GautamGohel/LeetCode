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
    ListNode *detectCycle(ListNode *head) {
        /*
        map<ListNode*,int>mp;
        ListNode* temp=head;
        while(temp){
            if(mp.find(temp)!=mp.end()){
                return temp;
            }
            else{
                mp[temp]=1;
            }
            temp=temp->next;
        }
        return NULL;
        */
        ListNode* slow=head;
        ListNode* fast=head;
        if(!head or !head->next){
            return NULL;
        }
        while(fast and fast->next){
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast){
              slow=head;
              while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
              }
              return slow;
           }
        }

        return NULL;
    }
};