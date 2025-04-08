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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
         ListNode* dummynode=new ListNode(-1);
        ListNode* temp=dummynode;
        while(head1 and head2){
            if(head1->val>head2->val){
                temp->next=head2;
                temp=head2;
                head2=head2->next;
            }else{
                temp->next=head1;
                temp=head1;
                head1=head1->next;
            }
        }
        if(head1){
            temp->next=head1;
        }else{
            temp->next=head2;
        }
        return dummynode->next;
    }
};