public class HeapSort {
  public static void sort(int[] arr) {
    Heap.make(arr);
    for (int i = arr.length; i > 0; i--) {
      Heap.delete(arr, i);
    }
  }
}
