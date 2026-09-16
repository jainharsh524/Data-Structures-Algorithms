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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* pu = nullptr;
        while(curr){
            if(curr->val != prev->val) pu = prev;
            else{
                while(curr && (curr->val == prev->val)) curr = curr->next;
                if(pu) pu->next = curr;
                else head = curr;
            }
            prev = curr;
            if(curr) curr = curr->next;
        }
        return head;
    }
};
