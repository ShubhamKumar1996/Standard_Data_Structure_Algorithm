#include<bits/stdc++.h>
#define int long long
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define deb(x) cout<<#x<<"="<<x<<"\n"
using namespace std;

int find_parent(vector<int>&parent, int curr){
    while(parent[curr]!= -1){
        curr = parent[curr];
    }
    return curr;
}

void Union(vector<int>&parent, int x, int y){
    parent[y] = x;
}

bool isCycle(){
    int vertex, edge; cin>>vertex>>edge;
    vector<int>parent(vertex+1, -1);
    for(int i=0;i<edge;i++){
        int src, des; cin>>src>>des;
        int parent1 = find_parent(parent, src);
        int parent2 = find_parent(parent, des);
        if(parent1 == parent2) return true;
        Union(parent, src, des);
    }
    return false;
}

int32_t main() {
    if(isCycle() == true)
        cout<<"Cycle Exist\n";
    else
        cout<<"No Cycle\n";
}