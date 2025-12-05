#include <iostream>
using namespace std;
class segmentTree{
    vector<int> tree, lazy;
    int n;
    segmentTree(vector<int> &arr){
        n = arr.size();
        tree.resize(4*n);
        lazy.resize(4*n, 0);
        build_tree(arr, 0, 0, n - 1);

    }
    void build_tree(vector<int> &arr, int treeIndex, int start, int end){
        if(start==end) {
            tree[treeIndex] = arr[start];
            return;
        }
        int mid = (start+end)/2;
        build_tree(arr, treeIndex*2+1, start, mid);
        build_tree(arr, treeIndex*2+2, mid+1, end);
        tree[treeIndex] = min(tree[treeIndex*2+1], tree[treeIndex*2+2]);
    }
    void pushDown(int treeIndex, int start, int end){
        if(lazy[treeIndex]!=0){
            tree[treeIndex] += lazy[treeIndex];
            if(start!=end){
                lazy[treeIndex*2+1] += lazy[treeIndex];
                lazy[treeIndex*2+2] += lazy[treeIndex];
            }
            lazy[treeIndex]=0;
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
        tree[treeIndex] = min(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
    }
    int rangeQuery(int treeIndex, int start, int end, int l, int r){
        pushDown(treeIndex, start, end);
        if(r<start||l>end){
            return 0;
        }
        if(l<=start&&end<=r){
            return tree[treeIndex];
        }
        int mid = (start+end)/2;
        int left = rangeQuery(treeIndex*2+1, start, mid, l, r);
        int right = rangeQuery(treeIndex*2+2, mid+1, end, l, r);
        return min(left, right);
    }
};
int main(){
    return 0;
}