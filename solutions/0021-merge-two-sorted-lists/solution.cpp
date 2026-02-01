class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode* res = nullptr;
        ListNode* resCurr = nullptr;

        // initialize head
        if (curr1->val < curr2->val) {
            res = new ListNode(curr1->val);
            curr1 = curr1->next;
        } else {
            res = new ListNode(curr2->val);
            curr2 = curr2->next;
        }
        resCurr = res;

        // merge
        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                resCurr->next = new ListNode(curr1->val);
                curr1 = curr1->next;
            } else {
                resCurr->next = new ListNode(curr2->val);
                curr2 = curr2->next;
            }
            resCurr = resCurr->next;
        }

        // remaining nodes
        while (curr1) {
            resCurr->next = new ListNode(curr1->val);
            curr1 = curr1->next;
            resCurr = resCurr->next;
        }

        while (curr2) {
            resCurr->next = new ListNode(curr2->val);
            curr2 = curr2->next;
            resCurr = resCurr->next;
        }

        return res;
    }
};

