import java.util.*;

public class Permutation {
    public static List<int[]> perms(int[] A) {
	List<int[]> soln = new ArrayList<int[]>();
	perms(A, 0, soln);
	return soln;
    }

    private static void perms(int[] A, int pos, List<int[]> soln) {
	if (pos == A.length) {
	    soln.add(Arrays.copyOf(A, A.length));
	    return;
	}
	for (int i = pos; i < A.length; i++) {
	    swap(A, pos, i);
	    perms(A, pos+1, soln);
	    swap(A, pos, i);
	}
    }

    private static void swap(int[] A, int i, int j) {
	int t = A[i];
	A[i] = A[j];
	A[j] = t;
    }
}
