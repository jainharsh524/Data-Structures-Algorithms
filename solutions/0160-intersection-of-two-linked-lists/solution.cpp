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
        if(headA==NULL||headB==NULL) return NULL;
        ListNode* ptra = headA;
        ListNode* ptrb = headB;
        while(ptra!=ptrb){
            if(ptra==NULL){
                ptra = headB;
            }
            else ptra = ptra->next;
            if(ptrb==NULL){
                ptrb = headA;
            }
            else ptrb = ptrb->next;
        }
        return ptra;
    }
};
