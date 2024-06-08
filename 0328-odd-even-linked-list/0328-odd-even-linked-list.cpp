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
    ListNode* oddEvenList(ListNode* head) {
        /*
        if(!head or !head->next){
           return head;
        }
        ListNode* temp=head;
        queue<int>q;
        while(temp and temp->next){
            q.push(temp->val);
            temp=temp->next->next;
        }
        if(temp){
            q.push(temp->val);
        }
        temp=head->next;
        while(temp and temp->next){
            q.push(temp->val);
            temp=temp->next->next;
        }
        if(temp){
            q.push(temp->val);
        }
        temp=head;
        while(temp){
            temp->val=q.front();
            q.pop();
            temp=temp->next;
        }
        return head;
        */
if(!head or !head->next){
    return head;
}

        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenhead=head->next;
        while(even and even->next){
                odd->next=odd->next->next;
                even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=evenhead;
        return head;
    }
};