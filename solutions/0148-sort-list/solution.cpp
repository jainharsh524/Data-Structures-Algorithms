class Solution {
public:
    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode dummy;
        ListNode* prev=&dummy;
        while(list1&&list2){
            if(list1->val<list2->val){
                prev->next=list1;
                list1=list1->next;
            }
            else{
                prev->next=list2;
                list2=list2->next;
            }
            prev=prev->next;
        }
        prev->next=list1 ? list1 : list2;
        return dummy.next;
    }
    ListNode* sorting(ListNode* head){
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* right=slow->next;
        slow->next=nullptr;
        ListNode* left=sorting(head);
        right=sorting(right);
        return merge(left,right);
    }
    ListNode* sortList(ListNode* head){
        return sorting(head);
    }
};
