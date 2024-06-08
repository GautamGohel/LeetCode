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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummyNode = new ListNode(-1); // Dummy node for the result
        ListNode* current = dummyNode; // Pointer to the current node in the result list
        int carry = 0;

        while (temp1 || temp2 || carry) {
            int val1 = (temp1) ? temp1->val : 0;
            int val2 = (temp2) ? temp2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;

            if (temp1) temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
        }

        return dummyNode->next; // The result starts from the next of the dummy node
    }
};
