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
    ListNode* middleNode(ListNode* head) {
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;
        if(!head->next){
            return head;
        }

        while (fastPointer and fastPointer->next) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        return slowPointer;
    }
};