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
    ListNode* calmid(ListNode* head, ListNode* end) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow != end && fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* lcurr, ListNode* rcurr) {
        ListNode* prev = new ListNode();
        ListNode* dummy = prev;
        while (lcurr && rcurr) {
            if (lcurr->val < rcurr->val) {
                prev->next = lcurr;
                lcurr = lcurr->next;
            } else {
                prev->next = rcurr;
                rcurr = rcurr->next;
            }
            prev = prev->next;
            prev->next = nullptr;
        }
        prev->next = (lcurr) ? lcurr : rcurr;
        return dummy->next;
    }
    ListNode* sorting(ListNode* head, ListNode* end) {
        if (head == end)
            return nullptr; 
        if (head->next == end) {
            head->next = nullptr;
            return head;
        }
        ListNode* mid = calmid(head, end);
        // Sort [head, mid)
        ListNode* left = sorting(head, mid);
        // Sort [mid, end)
        ListNode* right = sorting(mid, end);
        return merge(left, right);
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL)
            return nullptr;
        head = sorting(head, nullptr);
        return head;
    }
};
