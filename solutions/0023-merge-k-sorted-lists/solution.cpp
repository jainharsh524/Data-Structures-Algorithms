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

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();

            curr->next = new ListNode(val);
            curr = curr->next;

            if (lists[idx] != NULL) {
                pq.push({lists[idx]->val, idx});
                lists[idx] = lists[idx]->next;
            }
        }

        return dummy.next;
    }
};

