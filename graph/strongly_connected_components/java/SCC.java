import java.util.*;

public class SCC {
  public static int[] scc(int[][] graph) {
    List<Integer> to = topologicalOrder(graph);
    return getCC(graph, to);
  }

  private static List<Integer> topologicalOrder(int[][] graph) {
    List<Integer> order = new ArrayList<Integer>();
    int n = graph.length;
    boolean[] visited = new boolean[n];
    for (int u = 0; u < n; u++) {
      if (!visited[u]) {
        topologicalDFS(graph, u, visited, order);
      }
    }
    return order;
  }

  private static void topologicalDFS(int[][] graph, int u, boolean[] visited, List<Integer> l) {
    visited[u] = true;
    for (int v : graph[u]) {
      if (!visited[v]) {
        topologicalDFS(graph, v, visited, l);
      }
    }
    l.add(u);
  }

  private static int[] getCC(int[][] graph, List<Integer> order) {
    int n = graph.length;
    int cc_cnt = 0;
    int[] cc = new int[n];
    boolean[] visited = new boolean[n];
    for (int u : order) {
      if (!visited[u]) {
        cc[u] = cc_cnt++;
        ccDFS(graph, u, visited, cc);
      }
    }
    return cc;
  }

  private static void ccDFS(int[][] graph, int u, boolean[] visited, int[] cc) {
    visited[u] = true;
    for (int v : graph[u]) {
      if (!visited[v]) {
        cc[v] = cc[u];
        ccDFS(graph, v, visited, cc);
      }
    }
  }
}
