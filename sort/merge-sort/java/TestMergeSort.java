import org.junit.*;
import static org.junit.Assert.*;

public class TestMergeSort {
    @Test
    public void EmptyArray() {
	int[] A = {};
	int[] sorted = MergeSort.sort(A);
	int[] expected = {};
	assertArrayEquals(expected, sorted);
    }

    @Test
    public void SingleElemArray() {
	int[] A = {1};
	int[] sorted = MergeSort.sort(A);
	int[] expected = {1};
	assertArrayEquals(expected, sorted);
    }

    @Test
    public void GeneralCase() {
	int[] A = {3,2,5,1,4};
	int[] sorted = MergeSort.sort(A);
	int[] expected = {1,2,3,4,5};
	assertArrayEquals(expected, sorted);
    }

    public static void main(String args[]) {
	org.junit.runner.JUnitCore.main("TestMergeSort");
    }
}
