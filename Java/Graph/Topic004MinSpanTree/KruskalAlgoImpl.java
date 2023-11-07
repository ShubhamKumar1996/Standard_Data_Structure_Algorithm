import java.util.*;

public class KruskalAlgoImpl
{
    private int numOfVertex;
    private ArrayList<ArrayList<Integer>> edgeList = new ArrayList<>();
    
    private void collectEdgesAndVertex() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Num of Vertex: ");
        numOfVertex = scanner.nextInt();
        System.out.print("Num of Edges: ");
        int numOfEdges = scanner.nextInt();
        System.out.print("Edges: ");
        for(int i=1;i<=numOfEdges;i++) {
            int src = scanner.nextInt();
            int dest = scanner.nextInt();
            int weight = scanner.nextInt();
            edgeList.add(new ArrayList<Integer>(Arrays.asList(src, dest, weight)));
        }
        scanner.close();
    }
    
    private void addEdgesToHeap(PriorityQueue<ArrayList<Integer>> minHeap) {
        for(ArrayList<Integer> edge: edgeList) {
            minHeap.add(edge);
        }
    }
    
    private int root(int vertex, int[] parents) {
        if(parents[vertex] == vertex) {
            return vertex;
        }
        int newParent = root(parents[vertex], parents);
        parents[vertex] = newParent;
        return newParent;
    }
    
    private boolean union(int src, int dest, int[] parents) {
        int srcParent = root(src, parents);
        int destParent = root(dest, parents);
        if(srcParent == destParent) {
            return false;
        }
        parents[destParent] = srcParent;
        return true;
    }
    
    private void KruskalsAlgoImplementation() {
        
        // MinHeap Creation.
        PriorityQueue<ArrayList<Integer>> minHeap = new PriorityQueue<>(new Comparator<ArrayList<Integer>>() {
            public int compare(ArrayList<Integer> arr1, ArrayList<Integer> arr2) {
                int edgeWeight1 = arr1.get(2);
                int edgeWeight2 = arr2.get(2);
                if(edgeWeight2 < edgeWeight1) {
                    return 1;
                }
                return -1;
            }
        });
        
        // Input edges with weight.
        collectEdgesAndVertex();
        
        // Inserting edges in minHeap
        addEdgesToHeap(minHeap);
        
        int []parents = new int[numOfVertex+1]; // Disjoint Set Union -> Cycle detection in undirected graph.
        for(int i=0;i<=numOfVertex;i++) {
            parents[i] = i;
        }
        
        int addedEdgeCount = 0;
        while(minHeap.isEmpty() == false && addedEdgeCount < numOfVertex) {
            ArrayList<Integer> edge = minHeap.remove();
            int src = edge.get(0), dest = edge.get(1), weight = edge.get(2);
            if(union(src, dest, parents) == true) {
                System.out.printf("%d -> %d = %d\n", src, dest, weight);
                addedEdgeCount++;
            } else {
                continue;
            }
        }
    }
	public static void main(String[] args) {
		// Kruskal's Algorithm for Minimum spanning Tree.
		KruskalAlgoImpl kruskalAlgoImpl = new KruskalAlgoImpl();
		kruskalAlgoImpl.KruskalsAlgoImplementation();
	}
}
