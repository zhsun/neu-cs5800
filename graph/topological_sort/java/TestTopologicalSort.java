import org.junit.*;
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

public class TestTopologicalSort {
  @Test
  public void LineGraph() {
    int[][] graph = {{1},{2},{3},{4},{}};
    int[] sorted = TopologicalSort.sort(graph);
    assertThat(findIndex(sorted,0), lessThan(findIndex(sorted,1)));
    assertThat(findIndex(sorted,1), lessThan(findIndex(sorted,2)));
    assertThat(findIndex(sorted,2), lessThan(findIndex(sorted,3)));
    assertThat(findIndex(sorted,3), lessThan(findIndex(sorted,4)));
  }

  @Test
  public void TreeGraph() {
    int[][] graph = {{1,2},{3,4},{5},{},{},{}};
    int[] sorted = TopologicalSort.sort(graph);
    assertThat(findIndex(sorted,0), lessThan(findIndex(sorted,1)));
    assertThat(findIndex(sorted,0), lessThan(findIndex(sorted,2)));
    assertThat(findIndex(sorted,1), lessThan(findIndex(sorted,3)));
    assertThat(findIndex(sorted,1), lessThan(findIndex(sorted,4)));
    assertThat(findIndex(sorted,2), lessThan(findIndex(sorted,5)));
  }

  @Test
  public void GeneralDAG() {
    int[][] graph = {{},{3,0},{0},{},{1,2},{6},{}};
    int[] sorted = TopologicalSort.sort(graph);
    assertThat(findIndex(sorted,1), lessThan(findIndex(sorted,3)));
    assertThat(findIndex(sorted,1), lessThan(findIndex(sorted,0)));
    assertThat(findIndex(sorted,2), lessThan(findIndex(sorted,0)));
    assertThat(findIndex(sorted,4), lessThan(findIndex(sorted,1)));
    assertThat(findIndex(sorted,4), lessThan(findIndex(sorted,2)));
    assertThat(findIndex(sorted,5), lessThan(findIndex(sorted,6)));
  }

  private static int findIndex(int[] l, int e) {
    for (int i = 0; i < l.length; i++) {
      if (l[i] == e) return i;
    }
    return -1;
  }

  public static void main(String[] args) {
    org.junit.runner.JUnitCore.main("TestTopologicalSort");
  }
}
