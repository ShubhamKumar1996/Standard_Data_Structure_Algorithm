import java.util.Map;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.List;

public class SingleFileGraphImpl2 {
    // ArrayList<Integer> for storing edge details (source, destination, weight).
    private Map<Integer, LinkedList<ArrayList<Integer>>> graph = new HashMap<>();
    private int numOfVertex;

    public void createGraph() {
        Scanner scanner = new Scanner(System.in);
        // System.out.println("Number of vertex: ");
        numOfVertex = scanner.nextInt();

        for(int i=0;i<=numOfVertex;i++) {
            graph.put(i, new LinkedList<>());
        }

        // System.out.println("Number of Edge: ");
        int numOfEdge = scanner.nextInt();
        
        // Add edges to graph
        for(int i=0;i<numOfEdge;i++) {
            int vertex1 = scanner.nextInt();
            int vertex2 = scanner.nextInt();
            int weight = scanner.nextInt();
            ArrayList<Integer> edge = new ArrayList<>(List.of(vertex2, weight));
            graph.get(vertex1).add(edge);
        }

        scanner.close();

        // Print Graph
        for(int i= 0; i<= numOfVertex; i++) {
            System.out.printf("%d -> ", i);
            for(ArrayList<Integer> edge: graph.get(i)) {
                System.out.printf("destination: %d ", edge.get(0));
                System.out.printf("weight: %d,", edge.get(1));
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        // Better Implementation of Graph. (Fast, easy and useable for Problem Solving)
        SingleFileGraphImpl2 obj = new SingleFileGraphImpl2();
        obj.createGraph();
    }
}
