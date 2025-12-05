#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build_tree(0, arr, 0, n - 1);
    }

    void build_tree(int treeIndex, vector<int>& arr, int start, int end) {
        if (start == end) {
            tree[treeIndex] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build_tree(2 * treeIndex + 1, arr, start, mid);
        build_tree(2 * treeIndex + 2, arr, mid + 1, end);
        tree[treeIndex] = min(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
    }

    int query(int treeIndex, int start, int end, int l, int r) {
        if (r < start || l > end) return INT_MAX; // no overlap
        if (l <= start && end <= r) return tree[treeIndex]; // total overlap
        int mid = (start + end) / 2;
        int left = query(2 * treeIndex + 1, start, mid, l, r);
        int right = query(2 * treeIndex + 2, mid + 1, end, l, r);
        return min(left, right);
    }

    void update(int treeIndex, int start, int end, int index, int val) {
        if (start == end) {
            tree[treeIndex] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
            update(2 * treeIndex + 1, start, mid, index, val);
        else
            update(2 * treeIndex + 2, mid + 1, end, index, val);

        tree[treeIndex] = min(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
    }
    int findFirstGE(int x, int treeIndex, int start, int end){
        if(tree[treeIndex]<x)return -1;
        if(start==end) return start;
        int mid = (start+end)/2;
        if(tree[2*treeIndex+1]>=x){
            return findFirstGE(x, treeIndex*2+1, start, end);
        }
        else{
            return findFirstGE(x, treeIndex*2+2, start, end);
        }
    }

    // Wrapper functions
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
    void update(int idx, int val) { update(0, 0, n - 1, idx, val); }
};

int main() {
    vector<int> arr = {1, 3, -2, 8, -7, 10};
    SegmentTree st(arr);

    cout << "Min [1,4] = " << st.query(1, 4) << endl; // should be -7
    st.update(2, -10); // arr[2] = -10
    cout << "After update, Min [1,4] = " << st.query(1, 4) << endl; // should be -10

    return 0;
}
