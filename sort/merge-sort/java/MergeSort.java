public class MergeSort {
    public static int[] sort(int[] A) {
	if (A == null || A.length < 2) return A;
	int n = A.length;
	int[] left = new int[n/2];
	System.arraycopy(A, 0, left, 0, n/2);
	int[] sorted_left = MergeSort.sort(left);
	int[] right = new int[n-n/2];
	System.arraycopy(A, n/2, right, 0, n-n/2);
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
