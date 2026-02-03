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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* l = head;
        ListNode* r = head;
        ListNode* conn = head;
        int lt = left;
        while(l){
            if(lt==1) break;
            l = l->next;
            r = r->next;
            if(lt>2) conn = conn->next;
            lt--;
            right--;
        }
        if(left>1){
            conn->next = NULL;
            ListNode* prev = NULL;
            ListNode* nex = NULL;
            ListNode* lc = l;
            while(right){
                nex = l->next;
                l->next = prev;
                prev = l;
                l = nex;
                right--;
            }
            conn->next = prev;
            lc->next = nex;
        }
        else if(left==1){
            ListNode* prev = NULL;
            ListNode* nex = NULL;
            ListNode* lc = l;
            while(right){
                nex = l->next;
                l->next = prev;
                prev = l;
                l = nex;
                right--;
            }
            lc->next = nex;
            return prev;
        }
        return head;
    }
};
