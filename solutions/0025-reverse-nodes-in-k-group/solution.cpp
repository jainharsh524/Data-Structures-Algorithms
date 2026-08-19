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
    ListNode* findk(ListNode* head, int k){
        ListNode* fast = head;
        while(fast && k){
            fast = fast->next;
            k--;
        }
        return fast;
    }
    int sze(ListNode* head){
        ListNode* fast = head;
        int k = 0;
        while(fast){
            fast = fast->next;
            k++;
        }
        return k;
    }
    ListNode* reverse(ListNode* head, ListNode* tail){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nex = nullptr;
        while(curr && curr!=tail){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        head->next = curr;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        int size = sze(head);
        if(size<k) return head;
        ListNode* nodek = findk(head, k);
        ListNode* reversed_prev = reverse(head, nodek);
        head -> next = reverseKGroup(nodek, k);
        return reversed_prev;
    }
};
