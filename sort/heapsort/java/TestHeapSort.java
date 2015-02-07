import org.junit.*;
import static org.junit.Assert.*;

public class TestHeapSort {
	@Test
	public void SingleElem() {
		int[] arr = {1};
		HeapSort.sort(arr);
		assertArrayEquals(new int[]{1}, arr);
	}

	@Test
	public void GeneralCase() {
		int[] arr = {3,2,6,5,1,8,7,9,4,10};
		HeapSort.sort(arr);
		assertArrayEquals(new int[]{1,2,3,4,5,6,7,8,9,10}, arr);
	}

	public static void main(String args[]) {
		org.junit.runner.JUnitCore.main("TestHeapSort");
	}
}
