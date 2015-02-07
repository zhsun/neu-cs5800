import org.junit.*;
import static org.junit.Assert.*;

public class TestHeap {
  @Test
  public void MaxHeap() {
    int arr[] = {1,3,2,6,4,5};
    Heap.make(arr);
    assertEquals(6, arr[0]);
    Heap.delete(arr, arr.length);
    assertEquals(5, arr[0]);
    assertEquals(6, arr[arr.length-1]);
    Heap.insert(arr, arr.length-1, 7);
    assertEquals(7, arr[0]);
  }

  public static void main(String args[]) {
    org.junit.runner.JUnitCore.main("TestHeap");
  }
}
