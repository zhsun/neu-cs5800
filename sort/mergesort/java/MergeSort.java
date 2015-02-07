import java.util.*;

public class MergeSort {
    public static int[] sort(int[] A) {
	if (A.length < 2) return A;
	int n = A.length;
	int[] left = Arrays.copyOfRange(A, 0, n/2);
	int[] right = Arrays.copyOfRange(A, n/2, n);
	int[] sorted_left = MergeSort.sort(left);
	int[] sorted_right = MergeSort.sort(right);
	return merge(sorted_left, sorted_right);
    }

    private static int[] merge(int[] A, int[] B) {
	int n = A.length;
	int m = B.length;
	int[] C = new int[n+m];
	int i = 0, j = 0, k = 0;
	while (i < n && j < m) {
	    if (A[i] < B[j]) {
		C[k++] = A[i++];
	    } else {
		C[k++] = B[j++];
	    }
	}
	while (i < n) {
	    C[k++] = A[i++];
	}
	while (j < m) {
	    C[k++] = B[j++];
	}
	return C;
    }
}
