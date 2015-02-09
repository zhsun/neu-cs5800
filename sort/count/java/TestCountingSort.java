import org.junit.*;
import static org.junit.Assert.*;

public class TestCountingSort {
  @Test
  public void GeneralCase() {
    int[] arr = {3,1,2,5,3,1,5,2,4};
    int[] sorted = CountingSort.sort(arr, 5, new IdentityMapper());
    assertArrayEquals(new int[]{1,1,2,2,3,3,4,5,5}, sorted);
  }

  public static void main(String[] args) {
    org.junit.runner.JUnitCore.main("TestCountingSort");
  }
}
