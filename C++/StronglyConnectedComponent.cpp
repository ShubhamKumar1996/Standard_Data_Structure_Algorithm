#include<bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<bool> VB;

VVI transposeGraph(VVI graph, int numOfVerticies) {
    VVI Tgraph(numOfVerticies, (VI()));
    for(int i=0;i<numOfVerticies;i++) {
        for(auto &adjVertex: graph[i]) {
            Tgraph[adjVertex].push_back(i);
        }
    }
    return Tgraph;
}

void DFS(VVI graph, VB &visited, stack<int>&stk, int currVertex) {
    visited[currVertex] = true;
    
    for(auto &adjVertex: graph[currVertex]) {
        if(visited[adjVertex] == false) {
            DFS(graph, visited, stk, adjVertex);
        }
    }
    stk.push(currVertex);
    return;
}

VVI findSCC(VVI &graph, int numOfVerticies) {
    VVI SCC;
    VB visited(numOfVerticies, false);
    stack<int>stk, stkSCC;
    for(int i = 0; i < numOfVerticies; i++) {
        if(visited[i] == false) {
            DFS(graph, visited, stk, i);
        }
    }
    visited.assign(numOfVerticies, false);
    graph = transposeGraph(graph, numOfVerticies);
    while(stk.empty() == false) {
        if(visited[stk.top()] == false) {
            DFS(graph, visited, stkSCC, stk.top());
            // storing component of scc in a vector and then pushing it to list of scc.
            vector<int>Component;
            while(stkSCC.empty() == false) {
                Component.push_back(stkSCC.top());
                stkSCC.pop();
            }
            SCC.push_back(Component);
        }
        stk.pop();
    }
    return SCC;
}

int main() {
    int numOfVerticies, numOfEdges;
    cin >> numOfVerticies >> numOfEdges ;
    VVI graph(numOfVerticies, (VI()));
    for(int i=0;i<numOfEdges;i++) {
        int src, des; cin >> src >> des ;
        graph[src].push_back(des);
    }
    cout << "\nGraph AdjList Representation \n";
    for(int i=0;i<numOfVerticies;i++) {
        cout << i << "->" ;
        for(auto &adjVerticies: graph[i]) {
            cout << adjVerticies << " ";
        }
        cout << "\n";
    }
    
    VVI sccList = findSCC(graph, numOfVerticies);
    cout << "\nStrongly Connected Component\n";
    for(auto &scc: sccList) {
        for(auto &element: scc) {
            cout << element << " ";
        }
        cout << "\n";
    }
}