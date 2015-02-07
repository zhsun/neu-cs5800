public class QuickSort {
  public static void sort(int[] A) {
    if (A == null) return;
    sort(A, 0, A.length-1);
  }

  private static void sort(int[] A, int low, int high) {
    if (low >= high) return;
    int pivot_pos = partition(A, low, high);
    sort(A, low, pivot_pos-1);
    sort(A, pivot_pos+1, high);
  }

  private static int partition(int[] A, int low, int high) {
    int pivot = A[high];
    int i = low - 1;
    for (int cur = low; cur < high; cur++) {
      if (A[cur] < pivot) {
        swap(A, ++i, cur);
      }
    }
    swap(A, ++i, high);
    return i;
  }

  private static void swap(int[] A, int i, int j) {
    int t = A[i];
    A[i] = A[j];
    A[j] = t;
  }
}
