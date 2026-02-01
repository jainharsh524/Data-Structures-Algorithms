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
    ListNode* recHelper(ListNode* head, ListNode*prev){
        if(head==NULL) return prev;
        else{
            ListNode* nex = head->next;
            head->next = prev;
            prev = head;
            return recHelper(nex, prev);
        }
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        return recHelper(curr, NULL);
        // ListNode* prev = NULL;
        // ListNode* nex = NULL;
        // while(curr!=NULL){
        //     nex = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nex;
        // }
        // return prev;
    }
};
