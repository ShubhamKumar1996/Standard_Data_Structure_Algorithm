/*
					Floyd-Warshall algorithm

1.	Important algorithm for finding the shortest path for each vertex pair in a weighted graph.
2.	Don't work well on graph with Negative cycle.
3.	Use DP

*/

#include<bits/stdc++.h>
#define INFINITE 1000
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	int numOfVertex; cin >> numOfVertex;
	vector<vector<int>>graph(numOfVertex, (vector<int>(numOfVertex, INFINITE)));
	for(int i=0;i<numOfVertex;i++) {
		for(int j=0;j<numOfVertex;j++) {
			cin >> graph[i][j];
		}
	}
	for(int k=0;k<numOfVertex;k++) {
		for(int i=0;i<numOfVertex;i++) {
			for(int j=0;j<numOfVertex;j++) {
				if(graph[i][k] < INFINITE && graph[k][j] < INFINITE) {
					if(graph[i][j] >= INFINITE || graph[i][j] > graph[i][k] + graph[k][j]) {
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}
	}
	for(int i=0;i<numOfVertex;i++) {
		for(int j=0;j<numOfVertex;j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}