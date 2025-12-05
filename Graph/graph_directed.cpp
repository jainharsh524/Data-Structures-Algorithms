#include <iostream>
using namespace std;

int main(){
    int v, e;
    cin>>v>>e;
    vector<int> adj_lst[v];   //Directed Graph 0 based indexing
    for(int i = 0;i<e;i++){
        int a, b;
        cin>>a>>b;
        adj_lst[a].push_back(b);
    }

    int mat[v+1][v+1];
    for(int i = 0;i<e;i++){
        int a, b;
        cin>>a>>b;
        mat[a][b] = 1; //Edge from only a to b
    }

    return 0;
}