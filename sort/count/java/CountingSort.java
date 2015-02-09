public class CountingSort {
  // 'k' specifies the range of key(A). [0...k].
  public static int[] sort(int[] A, int k, MapInt key) {
    int[] C = new int[k+1];
    for (int i = 0; i < A.length; i++) {
      C[key.map(A[i])]++;
    }
    for (int i = 1; i < C.length; i++) {
      C[i] += C[i-1];
    }
    int[] B = new int[A.length];
    for (int i = A.length-1; i >= 0; i--) {
      int pos = C[key.map(A[i])] - 1;
      B[pos] = A[i];
      C[key.map(A[i])]--;
    }
    return B;
  }
}
