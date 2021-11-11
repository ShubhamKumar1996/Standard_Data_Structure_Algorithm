// Check graph is Bipartite or not. 
//Graph can be disconnected and don't have any self loops and paralled edges.

#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(vector<vector<int>>&graph) {
	if(graph.empty() == true) return true;
	int numOfVertex = graph.size();
	vector<bool>visited(numOfVertex, false);
    vector<int>color(numOfVertex, -1);
    for(int i=0;i<numOfVertex;i++) {
        if(visited[i] == true) continue;
        queue<int>q; q.push(i); visited[i] = true; color[i] = 1;
        while(q.empty() == false) {
            int currVertex = q.front(); q.pop();
            for(int adjVertex: graph[currVertex]) {
                if(visited[adjVertex] == true) {
                    if(color[adjVertex] == color[currVertex]) return false;
                } else {
                    q.push(adjVertex); visited[adjVertex] = true; color[adjVertex] = (color[currVertex] + 1)%2;
                }
            }
        }
    }
    return true;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	int numOfVertex, numOfEdge; cin >> numOfVertex >> numOfEdge ;
	vector<vector<int>>graph(numOfVertex, (vector<int>()));
	for(int i=0;i<numOfEdge;i++) {
		int vertex1, vertex2; cin >> vertex1 >> vertex2 ;
		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}
	(checkBipartite(graph) == true) ? cout << "Yes" : cout << "No" ;
}