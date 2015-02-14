import java.util.*;
import org.apache.commons.lang3.ArrayUtils;

public class TopologicalSort {
  // TopologicalSort takes a DAG in adjacency list format, and output
  // the topological order.
  public static int[] sort(int[][] graph) {
    int n = graph.length;
    boolean[] visited = new boolean[n];
    List<Integer> l = new ArrayList<Integer>();
    for (int u = 0; u < n; u++) {
      if (!visited[u]) {
        explore(graph, u, visited, l);
      }
    }
    Collections.reverse(l);
    return ArrayUtils.toPrimitive(l.toArray(new Integer[l.size()]));
  }

  private static void explore(int[][] graph, int u, boolean[] visited, List<Integer> l) {
    visited[u] = true;
    for (int v : graph[u]) {
      if (!visited[v]) {
        explore(graph, v, visited, l);
      }
    }
    l.add(u);
  }
}
