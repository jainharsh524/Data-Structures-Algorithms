#include <iostream>
using namespace std;
class segmentTree{
    vector<int> tree, lazy;
    int n;
    public: 
    segmentTree(vector<int> &arr){
        n = arr.size();
        tree.resize(4*n);
        lazy.resize(4*n, 0);
    }
    void build_tree(vector<int> &arr, int treeIndex, int start, int end){
        if (start == end) {
            tree[treeIndex] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build_tree(arr, 2 * treeIndex + 1, start, mid);
            build_tree(arr, 2 * treeIndex + 2, mid + 1, end);
            tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
        }
    }
    void pushDown(int treeIndex, int start, int end){
        if(lazy[treeIndex]!=0){
            tree[treeIndex] = tree[treeIndex]+(end-start+1)*lazy[treeIndex];
            if(start!=end){
                lazy[2*treeIndex+1] = lazy[2*treeIndex+1]+lazy[treeIndex];
                lazy[2*treeIndex+2] = lazy[2*treeIndex+2]+lazy[treeIndex];
            }
            lazy[treeIndex] = 0;
        }
    }
    void updateRange(int treeIndex, int start, int end, int l, int r, int val){
        pushDown(treeIndex, start, end);
        if (r < start || end < l) return; // no overlap
        if (l <= start && end <= r) {
            lazy[treeIndex] = lazy[treeIndex]+val;
            pushDown(treeIndex, start, end);
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2 * treeIndex + 1, start, mid, l, r, val);
        updateRange(2 * treeIndex + 2, mid + 1, end, l, r, val);
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }
    int queryRange(int treeIndex, int start, int end, int l, int r){
        pushDown(treeIndex, start, end);
        if(r<start||end<l) return 0;
        if(l<=start&&end<=r) return tree[treeIndex];
        int mid = (start+end)/2;
        int left = queryRange(treeIndex*2+1, start, mid, l, r);
        int right = queryRange(treeIndex*2+2, mid+1, end, l, r);
        return left+right;
    }
    int queryRange(int l, int r){
        return queryRange(0, 0, n-1, l, r);
    }
    void updateRange(int l, int r, int val){
        updateRange(0, 0, n-1, l, r, val);
    }
};
int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    segmentTree st(arr);

    cout << "Sum [0,4] = " << st.queryRange(0, 4) << endl; // 15
    st.updateRange(1, 3, 5); // add +5 to arr[1..3]
    cout << "After update, Sum [0,4] = " << st.queryRange(0, 4) << endl; // 30
    cout << "Query [1,3] = " << st.queryRange(1, 3) << endl; // (7+8+9)=24

    return 0;
}