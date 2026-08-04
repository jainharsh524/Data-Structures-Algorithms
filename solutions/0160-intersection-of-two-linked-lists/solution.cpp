/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA->next==NULL&&headB->next==NULL&&headA!=headB) return NULL;
        ListNode* slow = headA;
        while(slow->next) slow = slow->next;
        ListNode* endA = slow;
        slow->next = headB;
        slow = headA;
        ListNode* fast = headA;
        while(slow->next&&fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) break;
        }
        if(slow!=fast){
            endA->next = NULL;
            return NULL;
        }
        slow = headA;
        while(slow->next&&fast->next&&fast->next->next&&slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        endA->next = NULL;
        return slow;
    }
};
