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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            count++;
            curr = curr->next;
        }
        curr = head;
        if(count%2!=0){
            int val = 0;
            while(curr!=NULL){
                val++;
                if(val == (count+1)/2) return curr;
                else curr = curr->next;
            }
        }
        else{
            int val = 0;
            while(curr!=NULL){
                val++;
                if(val == (count+2)/2) return curr;
                else curr = curr->next;
            }
        }
        return NULL;
    }
};
