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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevptr=NULL;
        ListNode* currptr=head;
        ListNode* nextptr;
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        if(cnt<k){
            return head;
        }
        int cntreverse=0;
        while(currptr and cntreverse<k){
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
            cntreverse++;
        }
       if(nextptr) head->next=reverseKGroup(nextptr,k);
        return prevptr;
    }
};