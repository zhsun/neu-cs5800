import org.junit.*;
import static org.junit.Assert.*;

public class TestQuickSort {
  @Test
  public void EmptyArray() {
    int[] A = {};
    QuickSort.sort(A);
    int[] expected = {};
    assertArrayEquals(expected, A);
  }

  @Test
  public void SingleElemArray() {
    int[] A = {1};
    QuickSort.sort(A);
    int[] expected = {1};
    assertArrayEquals(expected, A);
  }

  @Test
  public void GeneralCase() {
    int[] A = {3,2,5,1,4};
    QuickSort.sort(A);
    int[] expected = {1,2,3,4,5};
    assertArrayEquals(expected, A);
  }

  public static void main(String args[]) {
    org.junit.runner.JUnitCore.main("TestQuickSort");
  }
}
