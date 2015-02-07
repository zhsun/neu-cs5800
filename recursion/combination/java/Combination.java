import java.util.*;

public class Combination {
  public static List<int[]> combs(int[] A) {
    List<int[]> soln = new ArrayList<int[]>();
    if (A.length == 0) {
      soln.add(new int[]{});
      return soln;
    }
    int[] first = new int[]{A[0]};
    int[] remain = Arrays.copyOfRange(A, 1, A.length);
    List<int[]> remain_combs = combs(remain);
    for (int[] comb : remain_combs) {
      soln.add(comb);
      soln.add(concatenate(first, comb));
    }
    return soln;
  }

  private static int[] concatenate(int[] A, int[] B) {
    int n = A.length;
    int m = B.length;
    int[] C = new int[n+m];
    System.arraycopy(A, 0, C, 0, n);
    System.arraycopy(B, 0, C, n, m);
    return C;
  }
}
