// using java to complete a more complicated task
import java.util.*;
import java.io.*;

class Graph {
    private Map<Character, List<Character>> adjList;

    public Graph() {
        adjList = new HashMap<>();
    }

    public void addEdge(char from, char to) {
        adjList.computeIfAbsent(from, k -> new ArrayList<>()).add(to);
    }

    public boolean isConnectedPath(char start, char end, List<Character> path) {
        Set<Character> visited = new HashSet<>();
        Queue<Character> queue = new LinkedList<>();
        Map<Character, Character> parent = new HashMap<>();

        queue.offer(start);
        visited.add(start);
        boolean found = false;


        while (!queue.isEmpty()) {
            char current = queue.poll();

            // break out of loop if the end node is found
            if (current == end) {
                found = true;
                break;
            }
            
            // if not, connect the nodes
            List<Character> neighbors = adjList.getOrDefault(current, new ArrayList<>());
            for (char neighbor : neighbors) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.offer(neighbor);
                    parent.put(neighbor, current);
                }
            }
        }

        if (found) {
            // reconstruct the path
            char node = end;
            while (node != start) {
                path.add(node);
                node = parent.get(node);
            }
            path.add(start);
            Collections.reverse(path);
        }

        return found;
    }
}

// driver program
public class p9 {
    public static void main(String[] args) {
        Graph graph = new Graph();

        graph.addEdge('A', 'B');
        graph.addEdge('B', 'A');
        graph.addEdge('B', 'C');
        graph.addEdge('B', 'D');
        graph.addEdge('D', 'G');
        graph.addEdge('D', 'E');
        graph.addEdge('B', 'E');
        graph.addEdge('E', 'F');
        graph.addEdge('F', 'B');
        graph.addEdge('C', 'F');
        graph.addEdge('F', 'G');

        Scanner input = new Scanner(System.in);

        // scan for the start and end node from user
        System.out.printf("Start = ");
        char start = input.next().charAt(0);

        System.out.printf("End   = ");
        char end = input.next().charAt(0);

        input.close();

        List<Character> path = new ArrayList<>();

        boolean isConnected = graph.isConnectedPath(start, end, path);
        
        if (isConnected) {
            System.out.println("True " + path);
        } else {
            System.out.println("False");
        }
    }
}
