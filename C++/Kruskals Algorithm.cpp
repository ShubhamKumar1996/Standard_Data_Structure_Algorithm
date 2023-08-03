#include<bits/stdc++.h>
#define int long long
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define deb(x) cout<<#x<<"="<<x<<"\n"
using namespace std;

bool comp(pair<int, pair<int, int>>&a, pair<int, pair<int, int>>&b){
    return a.first < b.first;
}

int find_parent(vector<int>&parent, int curr){
    while(parent[curr]!= -1){
        curr = parent[curr];
    }
    return curr;
}

void Union(vector<int>&parent, int x, int y){
    parent[x] = y;
}

void kruskals_algorithm(){
    int vertex, edge; cin>>vertex>>edge;
    vector<pair<int, pair<int, int>>>edges(edge);
    vector<int>parent(vertex+1, -1);
    for(int i=0;i<edge;i++){
        int weight, src, des; cin>>src>>des>>weight;
        edges[i].first = weight; edges[i].second.first = src; edges[i].second.second = des;
    }
    sort(edges.begin(), edges.end(), comp);
    int count = 0;
    for(auto &x: edges){
        int src = x.second.first, des = x.second.second, weight = x.first;
        int parent1 = find_parent(parent, src);
        int parent2 = find_parent(parent, des);
        if(parent1 != parent2){
            Union(parent, parent1, parent2);
            cout<<src<<" "<<des<<" "<<weight<<"\n";
            count++;
            if(count==vertex-1) break;
        }
    }
}

int32_t main() {
    kruskals_algorithm();
}