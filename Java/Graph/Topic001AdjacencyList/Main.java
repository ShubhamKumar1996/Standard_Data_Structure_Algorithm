import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        /*
         * Adjacency List implementation of Undirected Graph
         */

        //AdjacencyListMapImplementation adjacencyList = null;
        AdjacencyListMapImplementation adjacencyList = null;
        Scanner scanner = new Scanner(System.in);

        // Input number of vertex.
        System.out.printf("Number of vertex: ");
        int numOfVertex = scanner.nextInt();

        adjacencyList = new AdjacencyListMapImplementation(numOfVertex);

        // Input: number of edges.        
        System.out.printf("Number of Edges: ");
        int numOfEdge = scanner.nextInt();

        // Add edges to graph / adjacency list
        System.out.printf("Enter All Edges (undirected Graph) (v1, v2): ");
        for(int i= 0; i< numOfEdge; i+= 1) {
            int vertex1 = scanner.nextInt();
            int vertex2 = scanner.nextInt();
            int weight = scanner.nextInt();
            adjacencyList.addEdge(vertex1, vertex2, weight);
        }

        // Print Adjacency List
        adjacencyList.printGraph();

        scanner.close();
    }
}
