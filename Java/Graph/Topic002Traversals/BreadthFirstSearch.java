import java.util.*;

public class BreadthFirstSearch {
    private Map<Integer, LinkedList<Integer>> graph;
    private int numOfVertex;
    private ArrayList<Boolean> visited;
    private void BFSTraversal(int srcVertex) {
        Queue<Integer> queue = new ArrayDeque<>();
        queue.add(srcVertex);
        visited.set(srcVertex, true);
        while(queue.isEmpty() == false) {
            int currVertex = queue.remove();
            System.out.printf("%d, ", currVertex);
            for(Integer adjacentVertex: graph.get(currVertex)) {
                if(visited.get(adjacentVertex) == false) {
                    visited.set(adjacentVertex, true);
                    queue.add(adjacentVertex);
                }
            }
        }
    }
    private void solution() {
        Scanner scanner = new Scanner(System.in);
        numOfVertex = scanner.nextInt();
        graph = new HashMap<>();
        for(int i=0;i<=numOfVertex;i++) {
            graph.put(i, new LinkedList<>());
        }
        int numOfEdge = scanner.nextInt();
        for(int i=0;i<numOfEdge;i++) {
            int vertex1 = scanner.nextInt();
            int vertex2 = scanner.nextInt();
            graph.get(vertex1).add(vertex2);
            graph.get(vertex2).add(vertex1);
        }
        scanner.close();
        visited = new ArrayList<>(Collections.nCopies(numOfVertex+1, false));
        BFSTraversal(0);
    }
    public static void main(String[] args) {
        BreadthFirstSearch obj = new BreadthFirstSearch();
        obj.solution();
    }
}
