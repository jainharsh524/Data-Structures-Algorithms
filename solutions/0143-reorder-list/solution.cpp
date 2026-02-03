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
    ListNode* reverseList(ListNode* node,ListNode* prev){
        ListNode* nex = NULL;
        while(node){
            nex = node->next;
            node->next = prev;
            prev = node;
            node = nex;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* rh = reverseList(second, NULL);
        ListNode* curr1 = head;
        ListNode* curr2 = rh;
        while(curr2){
            ListNode* temp1 = curr1->next;
            ListNode* temp2 = curr2->next;
            curr1->next = curr2;
            curr2->next = temp1;
            curr1 = temp1;
            curr2 = temp2;
        }
    }
};
