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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        ListNode* fast = head;
        int size = 0;
        while(fast){
            fast = fast->next;
            size++;
        }
        if(size==1||k==0){
            return head;
        }
        k = k%size;
        fast = head;
        for(int i = 0;i<=k;i++){
            fast = fast->next;
        }
        ListNode* slow = head;
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* h1 = slow->next;
        if(h1==NULL) return head;
        slow->next = NULL;
        ListNode* curr2 = h1;
        while(curr2->next) curr2 = curr2->next;
        curr2->next = head;
        return h1;
    }
};
