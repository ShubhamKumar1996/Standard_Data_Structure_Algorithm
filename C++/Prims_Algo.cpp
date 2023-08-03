#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int findVertex(vector<int>&distance, vector<bool>&visited, int numOfVertex) {
	int minDistance = MAX, vertex = -1;
	for(int i=0;i<numOfVertex;i++) {
		if(distance[i] < minDistance && visited[i] == false) {
			minDistance = distance[i];
			vertex = i;
		}
	}
	if(vertex == -1) {
		cout << "Graph is disconnected";
		exit(0);
	}
	return vertex;
}

void primsAlgo(vector<vector<int>>&mat, int numOfVertex) {
	vector<int>distance(numOfVertex, MAX);
	vector<bool>visited(numOfVertex, false);
	distance[0] = 0;
	int totalCostMST = 0;
	for(int i=0;i<numOfVertex;i++) {
		int currVertex = findVertex(distance, visited, numOfVertex);
		cout << currVertex << "-> " << distance[currVertex] << "\n";
		totalCostMST += distance[currVertex];
		visited[currVertex] = true;
		for(int j=0;j<numOfVertex;j++) {
			if(mat[currVertex][j] < MAX) {
				if(visited[j] == false) {
					if(distance[j] > mat[currVertex][j]) {
						distance[j] = mat[currVertex][j];
					}
				}
			}
		}
	}
	cout << "Total Weight of MST: " << totalCostMST << "\n";

}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	int numOfVertex; cin >> numOfVertex ;
	vector<vector<int>>mat(numOfVertex, (vector<int>(numOfVertex)));
	for(int i=0;i<numOfVertex;i++) {
		for(int j=0;j<numOfVertex;j++) {
			cin >> mat[i][j];
		}
	}
	primsAlgo(mat, numOfVertex);
}