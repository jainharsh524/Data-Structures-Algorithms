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

    // Reverse linked list from head till end(exclusive)
    ListNode* reverseK(ListNode* head, ListNode* end) {

        ListNode* prev = end;
        ListNode* curr = head;

        while (curr != end) {

            ListNode* nex = curr->next;

            curr->next = prev;

            prev = curr;

            curr = nex;
        }

        // prev becomes new head
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1)
            return head;

        ListNode* curr = head;
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        if (count == k) {
            ListNode* newHead = reverseK(head, curr);
            head->next = reverseKGroup(curr, k);
            return newHead;
        }
        return head;
    }
};
