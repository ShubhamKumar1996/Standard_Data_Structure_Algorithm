import java.util.*;

public class DepthFirstSearch {
    private Map<Integer, LinkedList<ArrayList<Integer>>> graph;
    private ArrayList<Boolean> visited;
    private int numOfVertex;
    private void DFSTraversal(int srcVertex) {
        visited.set(srcVertex, true);
        System.out.printf("%d, ", srcVertex);
        for(ArrayList<Integer> adjacentVertex: graph.get(srcVertex)) {
            int nextVertex = adjacentVertex.get(0);
            if(visited.get(nextVertex) == false) {
                DFSTraversal(nextVertex);
            }
        }
    }
    private void solution() {
        // Taking Input.
        Scanner scanner = new Scanner(System.in);
        numOfVertex = scanner.nextInt();
        // Creating graph
        graph = new HashMap<>();
        for(int i=0;i<=numOfVertex;i++) {
            graph.put(i, new LinkedList<>());
        }
        // Adding Edges
        int numOfEdge = scanner.nextInt();
        for(int i=0;i<numOfEdge;i++) {
            int vertex1 = scanner.nextInt();
            int vertex2 = scanner.nextInt();
            int weight = scanner.nextInt();
            graph.get(vertex1).add(new ArrayList<>(List.of(vertex2, weight)));
            graph.get(vertex2).add(new ArrayList<>(List.of(vertex1, weight)));
        }
        scanner.close();

        // Initializing visited List.
        visited = new ArrayList<Boolean>(Collections.nCopies(numOfVertex+1, false));

        //BFS
        DFSTraversal(0);
    }
    public static void main(String[] args) {
        DepthFirstSearch obj = new DepthFirstSearch();
        obj.solution();
    }
}
