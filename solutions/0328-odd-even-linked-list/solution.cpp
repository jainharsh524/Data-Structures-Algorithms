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
        if(!head) return NULL;
        ListNode* evhead = head;
        ListNode* evprev = NULL;
        ListNode* odhead = head->next;
        ListNode* odcurr = odhead;
        while(odcurr&&evhead&&evhead->next){
            evhead->next = evhead->next->next;
            evprev = evhead;
            evhead = evhead->next;
            if(evhead){
                odcurr->next = evhead->next;
                odcurr = odcurr->next;
                // if(odcurr) cout<<odcurr->val<<" ";
            }
        }
        if(evhead) evhead->next = odhead;
        else evprev->next = odhead;
        return head;
    }
};
