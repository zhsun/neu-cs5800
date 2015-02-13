public class DFS {
  public static boolean hasCycle(int[][] graph) {
    int n = graph.length;
    int[] color = new int[n];
    for (int u = 0; u < n; u++) {
      if (color[u] == WHITE) {
        if (explore(graph, u, color)) {
          return true;
        }
      }
    }
    return false;
  }

  private static boolean explore(int[][] graph, int u, int[] color) {
    color[u] = GREY;
    for (int v : graph[u]) {
      if (color[v] == GREY) return true;
      if (color[v] == WHITE) {
        if (explore(graph, v, color)) {
          return true;
        }
      }
    }
    color[u] = BLACK;
    return false;
  }

  private static final int WHITE = 0;
  private static final int GREY = 1;
  private static final int BLACK = 2;
}
