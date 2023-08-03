import java.util.LinkedList;

public class AdjacencyListArrayImplementation {
    private int numOfVertex;
    private LinkedList<Edge> []graph;
    public AdjacencyListArrayImplementation(int numOfVertex) {
        this.numOfVertex = numOfVertex;
        graph = new LinkedList[numOfVertex+1];
        for(int i=0;i<=numOfVertex;i++) {
            graph[i] = new LinkedList<>();
        }
    }
    public void addEdge(int vertex1, int vertex2, int weight) {
        graph[vertex1].add(new Edge(vertex2, weight));
    }
    public void printGraph() {
        for(int i= 0; i<= numOfVertex; i++) {
            System.out.printf("%d -> ", i);
            for(Edge edge: graph[i]) {
                System.out.printf(edge.toString());
            }
            System.out.println();
        }
    }
}
