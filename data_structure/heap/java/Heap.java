// Max heap.
public class Heap {
    public static void make(int[] arr) {
	for (int i = arr.length; i >= 0; i--) {
	    heapify(arr, arr.length, i);
	}
    }

    public static void insert(int[] arr, int heap_size, int value) {
	arr[heap_size] = value;
	int i = heap_size;
	while (hasParent(i) && arr[parent(i)] < arr[i]) {
	    swap(arr, i, parent(i));
	    i = parent(i);
	}
    }

    public static void delete(int[] arr, int heap_size) {
	swap(arr, 0, heap_size-1);
	heapify(arr, heap_size-1, 0);
    }

    private static int parent(int pos) {
	return (pos - 1) / 2;
    }

    private static int left(int pos) {
	return 2 * pos + 1;
    }

    private static int right(int pos) {
	return 2 * pos + 2;
    }

    private static boolean hasParent(int pos) {
	return pos != 0;
    }

    private static boolean hasLeft(int pos, int heap_size) {
	return left(pos) < heap_size;
    }

    private static boolean hasRight(int pos, int heap_size) {
	return right(pos) < heap_size;
    }

    private static void heapify(int[] arr, int heap_size, int pos) {
	int largest = pos;
	if (hasLeft(pos, heap_size) &&
	    arr[largest] < arr[left(pos)]) {
	    largest = left(pos);
	}
	if (hasRight(pos, heap_size) &&
	    arr[largest] < arr[right(pos)]) {
	    largest = right(pos);
	}
	if (largest != pos) {
	    swap(arr, largest, pos);
	    heapify(arr, heap_size, largest);
	}
    }

    private static void swap(int[] arr, int i, int j) {
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
    }
}
