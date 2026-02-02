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
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* res = l1;
        int resu = 0;
        while(curr1&&curr2){
            int val1 = curr1->val;
            int val2 = curr2->val;
            resu = resu+val1+val2;
            res->val = resu%10;
            resu = resu/10;
            curr1 = curr1->next;
            curr2 = curr2->next;
            res = res->next;
        }
        while(curr1){
            int val1 = curr1->val;
            resu = resu+val1;
            res->val = resu%10;
            resu = resu/10;
            curr1 = curr1->next;
            res = res->next;
        }
        res = l1;
        while(res->next) res = res->next;
        while(curr2){
            int val2 = curr2->val;
            resu = resu+val2;
            res->next = new ListNode(resu%10);
            resu = resu/10;
            curr2 = curr2->next;
            res = res->next;
        }
        while(resu>0){
            res->next = new ListNode(resu%10);
            resu = resu/10;
            res = res->next;
        }
        return l1;
    }
};
