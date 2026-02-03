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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* currHead = head;
        int size = 0;
        while(currHead){
            currHead = currHead->next;
            size++;
        }
        currHead = head;
        if(size<k){
            return currHead;
        }
        int ptr = 0;
        ListNode* prev = NULL;
        ListNode* nex = NULL;
        ListNode* cc = currHead;
        while(currHead){
            if(ptr==k) break;
            nex = currHead->next;
            currHead->next = prev;
            prev = currHead;
            currHead = nex;
            ptr++;
        }
        cc->next = reverseKGroup(currHead, k);
        return prev;
    }
};
