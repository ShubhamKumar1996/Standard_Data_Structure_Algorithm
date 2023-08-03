import java.util.ArrayList;
import java.util.LinkedList;

public class AdjacencyListArrayListImplementation {
    private int numOfVertex;
    private ArrayList<LinkedList<Edge>> graph;
    public AdjacencyListArrayListImplementation(int numOfVertex) {
        this.numOfVertex = numOfVertex;
        graph = new ArrayList<>();
        for(int i=0;i<=numOfVertex;i++) {
            graph.add(new LinkedList<>());
        }
    }
    public void addEdge(int vertex1, int vertex2, int weight) {
        graph.get(vertex1).add(new Edge(vertex2, weight));
    }
    public void printGraph() {
        for(int i= 0; i<= numOfVertex; i++) {
            System.out.printf("%d -> ", i);
            for(Edge edge: graph.get(i)) {
                System.out.printf(edge.toString());
            }
            System.out.println();
        }
    }
}
