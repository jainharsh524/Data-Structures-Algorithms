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
        if(head==NULL) return NULL;
        ListNode* evhead = head;
        ListNode* oddhead = head->next;
        ListNode* evcurr = evhead;
        ListNode* oddcurr = oddhead;
        while(evcurr && oddcurr && oddcurr->next){
            evcurr->next = oddcurr->next;
            evcurr = evcurr->next;
            oddcurr->next = evcurr->next;
            oddcurr = oddcurr->next;
        }
        evcurr->next = oddhead;
        return evhead;
    }
};
