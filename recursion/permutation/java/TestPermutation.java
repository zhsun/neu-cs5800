import org.junit.*;
import static org.junit.Assert.*;
import static org.junit.matchers.JUnitMatchers.*;

import java.util.*;

public class TestPermutation {
    @Test
    public void ZeroElem() {
	int[] A = {};
	List<int[]> perms = Permutation.perms(A);
	assertEquals(1, perms.size());
	assertThat(perms, hasItem(new int[]{}));
    }

    @Test
    public void SingleElem() {
	int[] A = {1};
	List<int[]> perms = Permutation.perms(A);
	assertEquals(1, perms.size());
	assertThat(perms, hasItem(new int[]{1}));
    }

    @Test
    public void GeneralCase() {
	int[] A = {1,2,3};
	List<int[]> perms = Permutation.perms(A);
	assertEquals(6, perms.size());
	assertThat(perms, hasItem(new int[]{1,2,3}));
	assertThat(perms, hasItem(new int[]{1,3,2}));
	assertThat(perms, hasItem(new int[]{2,1,3}));
	assertThat(perms, hasItem(new int[]{2,3,1}));
	assertThat(perms, hasItem(new int[]{3,1,2}));
	assertThat(perms, hasItem(new int[]{3,2,1}));
    }

    public static void main(String args[]) {
	org.junit.runner.JUnitCore.main("TestPermutation");
    }
}
