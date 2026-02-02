class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: find length
        int size = 0;
        ListNode* curr = head;
        while (curr) {
            size++;
            curr = curr->next;
        }

        // Step 2: move to middle
        curr = head;
        for (int i = 0; i < (size - 1) / 2; i++) {
            curr = curr->next;
        }

        // Step 3: reverse second half
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* second = curr->next;  // start of second half
        curr->next = NULL;              // disconnect first half

        while (second) {
            next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // Step 4: compare halves
        ListNode* first = head;
        ListNode* secondHalf = prev;

        while (secondHalf) {
            if (first->val != secondHalf->val)
                return false;
            first = first->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};

