public class OrderStats {
    public static Integer kth(int[] A, int k) {
	return kth(A, k, 0, A.length-1);
    }

    private static Integer kth(int[] A, int k, int low, int high) {
	if (low > high || high - low + 1 < k) return null;
	int pivot_pos = partition(A, low, high);
	int pivot_rank = pivot_pos - low + 1;
	if (pivot_rank == k) return A[pivot_pos];
	if (pivot_rank > k) return kth(A, k, low, pivot_pos-1);
	return kth(A, k-pivot_rank, pivot_pos+1, high);
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
