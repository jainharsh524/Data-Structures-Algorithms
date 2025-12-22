class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push({lists[i]->val, i});
                lists[i] = lists[i]->next;
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            tail->next = new ListNode(val);
            tail = tail->next;

            if (lists[idx] != NULL) {
                pq.push({lists[idx]->val, idx});
                lists[idx] = lists[idx]->next;
            }
        }

        return dummy->next;
    }
};

