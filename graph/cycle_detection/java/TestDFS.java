import org.junit.*;
import static org.junit.Assert.*;

public class TestDFS {
  @Test
  public void GraphWithNoEdge() {
    int[][] g = {{},{},{},{},{}};
    assertFalse(DFS.hasCycle(g));
  }

  @Test
  public void CycleGraph() {
    int[][] g = {{1},{2},{3},{4},{0}};
    assertTrue(DFS.hasCycle(g));
  }

  @Test
  public void TreeGraph() {
    int[][] g = {{1,2},{3,4},{5},{},{},{}};
    assertFalse(DFS.hasCycle(g));
  }

  @Test
  public void DAG() {
    int[][] g = {{1,2},{3,4},{3,4},{},{3}};
    assertFalse(DFS.hasCycle(g));
  }

  @Test
  public void GeneralCase() {
    int[][] g = {{1,2,4},{},{1,3},{0},{2,3}};
    assertTrue(DFS.hasCycle(g));
  }

  public static void main(String args[]) {
    org.junit.runner.JUnitCore.main("TestDFS");
  }
}
