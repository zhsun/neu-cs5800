import org.junit.*;
import static org.junit.Assert.*;
import static org.junit.matchers.JUnitMatchers.*;

import org.javatuples.*;

public class TestStrassen {
  @Test
  public void NextPowerOfTwo() {
    assertEquals(1, Strassen.nextPowerOfTwo(0));
    assertEquals(1, Strassen.nextPowerOfTwo(1));
    assertEquals(2, Strassen.nextPowerOfTwo(2));
    assertEquals(4, Strassen.nextPowerOfTwo(3));
    assertEquals(16, Strassen.nextPowerOfTwo(13));
    assertEquals(16, Strassen.nextPowerOfTwo(16));
  }

  @Test
  public void Add() {
    int[][] A = {{1,2},{3,4}};
    int[][] B = {{1,1},{1,1}};
    int[][] expected = {{2,3},{4,5}};
    assertArrayEquals(expected, Strassen.add(A,B));
  }

  @Test
  public void Minus() {
    int[][] A = {{1,2},{3,4}};
    int[][] B = {{1,1},{1,1}};
    int[][] expected = {{0,1},{2,3}};
    assertArrayEquals(expected, Strassen.minus(A,B));
  }

  @Test
  public void CopyMatrix() {
    int[][] A = {{1,1},{2,2}};
    int[][] B = new int[4][4];
    Strassen.copyMatrix(A, B, A.length, 0, 0);
    int[][] expected_b = new int[][]{{1,1,0,0},
                                     {2,2,0,0},
                                     {0,0,0,0},
                                     {0,0,0,0}};
    assertArrayEquals(expected_b, B);
    int[][] C = new int[4][4];
    Strassen.copyMatrix(A, C, A.length, 1, 1);
    int[][] expected_c = new int[][]{{0,0,0,0},
                                     {0,1,1,0},
                                     {0,2,2,0},
                                     {0,0,0,0}};
    assertArrayEquals(expected_c, C);
  }

  @Test
  public void GetBlockMatrix() {
    int[][] A = {{1,2},{3,4}};
    Quartet<int[][],int[][],int[][],int[][]> all = Strassen.getBlockMatrix(A);
    assertArrayEquals(new int[][]{{1}}, all.getValue0());
    assertArrayEquals(new int[][]{{2}}, all.getValue1());
    assertArrayEquals(new int[][]{{3}}, all.getValue2());
    assertArrayEquals(new int[][]{{4}}, all.getValue3());
  }

  @Test
  public void StrassenEven() {
    int[][] A = {{1,1},{1,1}};
    int[][] B = {{1,2},{3,4}};
    int[][] expected = {{4,6},{4,6}};
    assertArrayEquals(expected, Strassen.strassen(A,B));
  }

  @Test
  public void StrassenOdd() {
    int[][] A = {{1,2,3},{2,3,4},{3,4,5}};
    int[][] B = {{1,1,1},{1,1,1},{1,1,1}};
    int[][] expected = {{6,6,6},{9,9,9},{12,12,12}};
    assertArrayEquals(expected, Strassen.strassen(A,B));
  }

  public static void main(String args[]) {
    org.junit.runner.JUnitCore.main("TestStrassen");
  }
}
