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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;
        for(int i = 0;i<lists.size();i++){
            if(lists[i]){ 
                pq.push({lists[i]->val, i});
                lists[i] = lists[i]->next;
            }
        }
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(!pq.empty()){
            int value = pq.top().first;
            curr->next = new ListNode(value);
            curr = curr->next;
            int ind = pq.top().second;
            pq.pop();
            if(lists[ind]){
                pq.push({lists[ind]->val, ind});
                lists[ind] = lists[ind]->next;
            }
        }
        return dummy->next;
    }
};
