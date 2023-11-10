/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
import java.util.*;

public class DijkstraAlgoImpl
{  
    private Map<Integer, LinkedList<ArrayList<Integer>>> adjList = new HashMap<>();
    private int numOfVertex;
    
    private void createAdjList() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Num of Vertex: ");
        numOfVertex = scanner.nextInt();
        System.out.print("Num of Edges: ");
        int numOfEdges = scanner.nextInt();
        System.out.println("Enter Edges: ");
        for(int i=1;i<=numOfEdges;i++) {
            int vertex1 = scanner.nextInt();
            int vertex2 = scanner.nextInt();
            int edgeWeight = scanner.nextInt();
            ArrayList<Integer> node = new ArrayList<>(Arrays.asList(vertex2, edgeWeight));
            if(adjList.containsKey(vertex1) == false) {
                adjList.put(vertex1, new LinkedList<ArrayList<Integer>>());
            }
            adjList.get(vertex1).add(node);
            node = new ArrayList<Integer>(Arrays.asList(vertex1, edgeWeight));
            if(adjList.containsKey(vertex2) == false) {
                adjList.put(vertex2, new LinkedList<ArrayList<Integer>>());
            }
            adjList.get(vertex2).add(node);
        }
        scanner.close();
    }
    
    
    private void DijkstraAlgoImplementation() {
        createAdjList();
        
        // Create minHeap
        PriorityQueue<ArrayList<Integer>> minHeap = new PriorityQueue<>(new Comparator<ArrayList<Integer>>() {
            public int compare(ArrayList<Integer> arr1, ArrayList<Integer> arr2) {
                int edgeWeight1 = arr1.get(2);
                int edgeWeight2 = arr2.get(2);
                if(edgeWeight1 < edgeWeight2) {
                    return -1;
                }
                return 1;
            }
        });
        
        // Create Visited array.
        boolean[] visited = new boolean[numOfVertex+1];
        
        // Push start node(0) to minHeap
        // NOTE: Assuming source vertex provided by user is 0.
        minHeap.add(new ArrayList<Integer>(Arrays.asList(0, 0, 0)));
        
        while(!minHeap.isEmpty()) {
            ArrayList<Integer> node = minHeap.remove();
            if(node == null) {
                continue;
            }
            int vertex = node.get(1);
            int edgeWeight = node.get(2);
            
            if(visited[vertex] == true) {
                continue;
            }
            visited[vertex] = true;
            
            System.out.printf("%d = %d\n", vertex, edgeWeight);
            
            if(adjList.containsKey(vertex) && adjList.get(vertex).isEmpty() == false) {
                for(ArrayList<Integer> adjNode : adjList.get(vertex)) {
                    int adjVertex = adjNode.get(0);
                    int adjVertexEdgeWeight = adjNode.get(1);
                    if(visited[adjVertex] == false) {
                        minHeap.add(new ArrayList<Integer>(Arrays.asList(vertex, adjVertex, edgeWeight + adjVertexEdgeWeight)));
                    }
                }
            }
        }
    }
	public static void main(String[] args) {
		// Dijkstra's Algorithm implementation.
		DijkstraAlgoImpl main = new DijkstraAlgoImpl();
		main.DijkstraAlgoImplementation();
	}
}
