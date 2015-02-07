import org.junit.*;
import static org.junit.Assert.*;
import static org.junit.matchers.JUnitMatchers.*;


public class TestOrderStats {
	@Test
	public void First() {
		int[] A = {5,7,2,1,4,9,8,3,6};
		assertEquals(new Integer(1), OrderStats.kth(A, 1));
	}

	@Test
	public void Middle() {
		int[] A = {5,7,2,1,4,9,8,3,6};
		assertEquals(new Integer(5), OrderStats.kth(A, 5));
	}

	@Test
	public void Last() {
		int[] A = {5,7,2,1,4,9,8,3,6};
		assertEquals(new Integer(9), OrderStats.kth(A, 9));
	}

	@Test
	public void OutOfBound() {
		int[] A = {5,7,2,1,4,9,8,3,6};
		assertEquals(null, OrderStats.kth(A, 10));
	}

	public static void main(String args[]) {
		org.junit.runner.JUnitCore.main("TestOrderStats");
	}
}
