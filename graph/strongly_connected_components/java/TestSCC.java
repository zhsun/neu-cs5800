import org.junit.*;
import static org.junit.Assert.*;
import static org.hamcrest.Matchers.*;

public class TestSCC {
  @Test
  public void NoEdgeGraph() {
    int[][] graph = {{},{},{},{},{}};
    int[] cc = SCC.scc(graph);
    assertThat(cc[0], not(cc[1]));
    assertThat(cc[0], not(cc[2]));
    assertThat(cc[0], not(cc[3]));
    assertThat(cc[0], not(cc[4]));
    assertThat(cc[1], not(cc[2]));
    assertThat(cc[3], not(cc[4]));
  }

  @Test
  public void TreeGraph() {
    int[][] graph = {{1,2},{3,4},{5},{},{},{}};
    int[] cc = SCC.scc(graph);
    assertThat(cc[0], not(cc[1]));
    assertThat(cc[0], not(cc[2]));
    assertThat(cc[0], not(cc[3]));
    assertThat(cc[0], not(cc[4]));
    assertThat(cc[0], not(cc[5]));
    assertThat(cc[1], not(cc[2]));
    assertThat(cc[3], not(cc[4]));
  }

  @Test
  public void GeneralGraph() {
    int[][] graph = new int[10][];
    graph[0] = new int[]{};
    graph[1] = new int[]{0,4};
    graph[2] = new int[]{1,5};
    graph[3] = new int[]{1};
    graph[4] = new int[]{1};
    graph[5] = new int[]{2};
    graph[6] = new int[]{4,7};
    graph[7] = new int[]{5,9};
    graph[8] = new int[]{6};
    graph[9] = new int[]{8};
    int[] cc = SCC.scc(graph);
    // 0 itself forms a cc.
    // 3 itself forms a cc.
    // 1 and 4 form a cc.
    // 2 and 5 form a cc.
    // 6, 7, 8, and 9 form a cc.
    assertThat(cc[1], is(cc[4]));
    assertThat(cc[2], is(cc[5]));
    assertThat(cc[6], is(cc[7]));
    assertThat(cc[6], is(cc[8]));
    assertThat(cc[6], is(cc[9]));
    // Check different cc are numbered differently.
    assertThat(cc[0], not(cc[1]));
    assertThat(cc[0], not(cc[2]));
    assertThat(cc[0], not(cc[3]));
    assertThat(cc[0], not(cc[6]));
    assertThat(cc[1], not(cc[2]));
    assertThat(cc[1], not(cc[3]));
    assertThat(cc[1], not(cc[6]));
    assertThat(cc[2], not(cc[3]));
    assertThat(cc[2], not(cc[6]));
    assertThat(cc[3], not(cc[6]));
  }

  public static void main(String args[]) {
    org.junit.runner.JUnitCore.main("TestSCC");
  }
}
