import org.junit.*;
import static org.junit.Assert.*;
import static org.junit.matchers.JUnitMatchers.*;

import java.util.*;

public class TestCombination {
  @Test
  public void ZeroElem() {
    int[] A = {};
    List<int[]> combs = Combination.combs(A);
    assertEquals(1, combs.size());
    assertThat(combs, hasItem(new int[]{}));
  }

  @Test
  public void SingleElem() {
    int[] A = {1};
    List<int[]> combs = Combination.combs(A);
    assertEquals(2, combs.size());
    assertThat(combs, hasItem(new int[]{}));
    assertThat(combs, hasItem(new int[]{1}));
  }

  @Test
  public void GeneralCase() {
    int[] A = {1,2,3};
    List<int[]> combs = Combination.combs(A);
    assertEquals(8, combs.size());
    assertThat(combs, hasItem(new int[]{}));
    assertThat(combs, hasItem(new int[]{1}));
    assertThat(combs, hasItem(new int[]{2}));
    assertThat(combs, hasItem(new int[]{3}));
    assertThat(combs, hasItem(new int[]{1,2}));
    assertThat(combs, hasItem(new int[]{1,3}));
    assertThat(combs, hasItem(new int[]{2,3}));
    assertThat(combs, hasItem(new int[]{1,2,3}));
  }

  public static void main(String args[]) {
    org.junit.runner.JUnitCore.main("TestCombination");
  }
}
