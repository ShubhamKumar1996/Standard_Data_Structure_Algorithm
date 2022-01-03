class Solution
{
	public:
	vector<int> computeInDegree(int numOfVertex, vector<int> adj[]) {
	    vector<int>inDegree(numOfVertex, 0);
	    for(int i=0;i<numOfVertex;i++) {
	        for(int &adjVertex: adj[i]) {
	            inDegree[adjVertex]++;
	        }
	    }
	    return inDegree;
	}
	
	void reduceInDegree(vector<int> adj[], vector<int>&inDegree, int currVertex, queue<int>&q) {
	    for(int &adjVertex: adj[currVertex]) {
	        inDegree[adjVertex]--;
	        int currDegree = inDegree[adjVertex];
	        if(currDegree == 0) {
	            q.push(adjVertex);
	        }
	    }
	}
	
	queue<int> insertZeroInDegreeVertex(vector<int>& inDegree) {
	    queue<int>q;
	    for(int i=0;i<inDegree.size();i++) {
	        int currDegree = inDegree[i];
	        if(currDegree == 0) {
	            q.push(i);   
	        }
	    }
	    return q;
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int numOfVertex, vector<int> adj[]) 
	{
	    if(numOfVertex < 0) return {};
	    vector<int>inDegree = computeInDegree(numOfVertex, adj);
	    vector<int> result;
	    queue<int>q = insertZeroInDegreeVertex(inDegree);
	    while(q.empty() == false) {
	        int currVertex = q.front(); q.pop();
	        result.push_back(currVertex);
	        reduceInDegree(adj, inDegree, currVertex, q);
	    }
	    return result;
	}
};