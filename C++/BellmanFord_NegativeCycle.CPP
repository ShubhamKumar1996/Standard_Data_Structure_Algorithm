/*

1.  Bellman Ford algorithm helps us find the shortest path from a vertex to all other vertices of a weighted graph.

2.  similar to Dijkstra's algorithm but it can work with graphs in which edges can have negative weights.

3.  Example of Negative weight edge: -
	3.1   Negative weight edge can explain a lot of phenomena like cashflow, the heat released/absorbed in a chemical reaction, etc.
	3.2	  Suppose we have different ways to reach from chemical A to chemical B;
	      Each of these methods will have sub reactions;
	      Each of this sub reaction will involve heat absorption and heat release;
	      If we want to find set of reactions where minimum energy is required;
	      then we can consider heat absorption as negative weight and heat emission as positive weight edge.

Why do we need to be careful with negative weights?

1.	Negative weight edges can create negative weight cycles. Negative weight cycle can give an incorrect result when we are trying to find shortest path.
2.	Dikstra's Algorithm can not detect Negative weight cycle.

How Bellman Ford's algorithm works.

1.	Bellman Ford algorithm works by overestimating the length of the path from the starting vertex to all other vertices.
2.	Then it iteratively relaxes those estimates by finding new paths that are shorter than the previously overestimated paths.
3.	By doing this repeatedly for all vertices, we can guarantee that the result is optimized.
4.	To detect negative weight cycle we will simply iterate through graph n-1 if after that also distance of some vertex is changing that means graph contains negative weight cycle.

*/

#include<bits/stdc++.h>
using namespace std;

struct Edge {
	int src, des, cost;
};

class Graph {
private:
	int numOfVertex, numOfEdge;
	vector<Edge>graph;
public:
	void createGraph();
	bool negativeWeightCycle();
};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	Graph G; G.createGraph();
	(G.negativeWeightCycle() == true) ? cout << "Yes" : cout << "No" ;
}

void Graph :: createGraph() {
	cin >> this->numOfVertex >> this->numOfEdge;
	for(int i=0;i<numOfEdge;i++) {
		Edge edge;
		cin >> edge.src >> edge.des >> edge.cost ;
		graph.push_back(edge);
	}
}

bool Graph :: negativeWeightCycle() {
	vector<int>distance(numOfVertex, INT_MAX); distance[0] = 0;
	bool changedAnyDistance;
	int iteration = 0;
	while(true) {
		changedAnyDistance = false;
		iteration++;
		for(int i=0;i<numOfEdge;i++) {
			if(distance[graph[i].src] != INT_MAX) {
				if(distance[graph[i].des] > distance[graph[i].src] + graph[i].cost) {
					distance[graph[i].des] = distance[graph[i].src] + graph[i].cost;
					changedAnyDistance = true;
				}
			}
		}
		if(changedAnyDistance == false) break;
		if(iteration == numOfVertex) return true;
	}
	return false;
}