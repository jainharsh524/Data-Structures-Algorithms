#include <iostream>
using namespace std;
class segmentTree{
    vector<int> tree;
    int n;
    public:
        segmentTree(vector<int> &arr){
            n = arr.size();
            tree.resize(4*n);
            build_tree(arr, 0, 0, n - 1);
        }
        void build_tree(vector<int> &arr, int treeIndex, int start, int end){
            if(start==end){
                tree[treeIndex]=arr[start];
            }
            else{
                int mid = (start+end)/2;
                build_tree(arr, 2*treeIndex+1, start, mid);
                build_tree(arr, 2*treeIndex+2, mid+1, end);
                tree[treeIndex] = tree[2*treeIndex+1]+tree[2*treeIndex+2];
            }
        }
        int query(int treeIndex, int start, int end, int l, int r){
            if(r<start||l>end)return 0;
            if(l<=start&&r>=end) return tree[treeIndex];
            int mid = (start+end)/2;
            int left = query(2*treeIndex+1, start, mid, l, r);
            int right = query(2*treeIndex+2, mid+1, end, l, r);
            return left+right;
        }
        void update(int treeIndex, int start, int end, int index, int val){
            if(start==end){
                tree[treeIndex] = val;
            }
            else{
                int mid = (start+end)/2;
                if(index<=mid){
                    update(2*treeIndex+1, start, mid, index, val);
                }
                else{
                    update(2*treeIndex+2, mid+1, end, index, val);
                }
                tree[treeIndex] = tree[2*treeIndex+1]+tree[2*treeIndex+2];
            }
        }
        int query(int l, int r) { return query(0, 0, n - 1, l, r); }
        void update(int idx, int val) { update(0, 0, n - 1, idx, val); }
};
int main(){
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    segmentTree st(arr);

    cout << "Sum [1,3] = " << st.query(1, 3) << endl; // 3+5+7=15
    st.update(1, 10); // arr[1] = 10
    cout << "After update, Sum [1,3] = " << st.query(1, 3) << endl; // 10+5+7=22

    return 0;
}