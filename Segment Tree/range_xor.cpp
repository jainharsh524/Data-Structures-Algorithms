#include <iostream>
using namespace std;
class segmentTree{
    vector<int> tree;
    int n;
    public:
    segmentTree(vector<int> &arr){
        n = arr.size();
        tree.resize(4*n);
    }
    void build_tree(vector<int>& arr, int treeIndex, int start, int end){
        if(start==end){
            tree[treeIndex] = arr[start];
            return;
        }
        int mid = (start+end)/2;
        build_tree(arr, treeIndex*2+1, start, mid);
        build_tree(arr, treeIndex, mid+1, end);
        tree[treeIndex] = tree[treeIndex*2+1]^tree[treeIndex*2+2];
    }
    void update(int treeIndex, int start, int end, int index, int val){
        if(start==end){
            tree[treeIndex] = val;
            return;
        }
        int mid = (start+end)/2;
        if(index<=mid){
            update(treeIndex*2+1, start, mid, index, val);
        }
        else{
            update(treeIndex*2+2, start, mid, index, val);
        }
        tree[treeIndex] = tree[treeIndex*2+1]^tree[treeIndex*2+2];
    }
    int queryRange(int treeIndex, int start, int end, int l, int r){
        if(r<start||l>end) return 0;
        if (l <= start && end <= r) return tree[treeIndex];
        int mid = (start+end)/2;
        int left = queryRange(treeIndex*2+1, start, mid, l, r);
        int right = queryRange(treeIndex*2+1, mid+1, end, l, r);
        return left^right;
    }
};
int main(){
    return 0;
}