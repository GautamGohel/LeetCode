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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp1=head;
        ListNode* temp2=head;
        int cnt=0;
        while(cnt<n){
            temp2=temp2->next;
            cnt++;
        }
        if(!temp2) return head->next;
        while(temp2->next){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp1->next=temp1->next->next;
        return head;
    }
};