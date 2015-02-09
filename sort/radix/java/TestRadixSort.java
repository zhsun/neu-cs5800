import org.junit.*;
import static org.junit.Assert.*;

public class TestRadixSort {
  @Test
  public void GeneralCase() {
    int[] arr = {465,321,474,355,123,
                 777,919,134,221,756};
    arr = RadixSort.sort(arr, 3);
    int[] expected = {123,134,221,321,355,
                      465,474,756,777,919};
    assertArrayEquals(expected, arr);
  }

  public static void main(String[] args) {
    org.junit.runner.JUnitCore.main("TestRadixSort");
  }
}
