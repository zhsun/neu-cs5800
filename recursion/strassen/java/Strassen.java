import org.javatuples.*;

public class Strassen {
    public static int[][] strassen(int[][] A, int[][] B) {
	int n = A.length;
	// Make the size power of two, so we don't need to deal with
	// odd cases in recursion.
	int m = nextPowerOfTwo(n);
	int[][] largeA = new int[m][m];
	copyMatrix(A, largeA, n, 0, 0);
	int[][] largeB = new int[m][m];
	copyMatrix(B, largeB, n, 0, 0);
	int[][] largeC = strassenRec(largeA, largeB);
	int[][] C = new int[n][n];
	copyMatrix(largeC, C, n, 0, 0);
	return C;
    }

    public static int[][] strassenRec(int[][] A, int[][] B) {
	int n = A.length;
	int[][] C = new int[n][n];
	if (n == 1) {
	    C[0][0] = A[0][0] * B[0][0];
	    return C;
	}
	Quartet<int[][],int[][],int[][],int[][]> allA = getBlockMatrix(A);
	int[][] a = allA.getValue0();
	int[][] b = allA.getValue1();
	int[][] c = allA.getValue2();
	int[][] d = allA.getValue3();
	Quartet<int[][],int[][],int[][],int[][]> allB = getBlockMatrix(B);
	int[][] e = allB.getValue0();
	int[][] g = allB.getValue1();
	int[][] f = allB.getValue2();
	int[][] h = allB.getValue3();
	// Calculate p1 to p7.
	int[][] p1 = strassenRec(a, minus(g,h));
	int[][] p2 = strassenRec(add(a,b), h);
	int[][] p3 = strassenRec(add(c,d), e);
	int[][] p4 = strassenRec(d, minus(f,e));
	int[][] p5 = strassenRec(add(a,d), add(e,h));
	int[][] p6 = strassenRec(minus(b,d), add(f,h));
	int[][] p7 = strassenRec(minus(a,c), add(e,g));
	// Use p1 to p7 to reconstruct the product matrix.
	copyMatrix(minus(add(add(p4,p5),p6),p2), C, n/2, 0, 0);
	copyMatrix(add(p1,p2), C, n/2, 0, n/2);
	copyMatrix(add(p3,p4), C, n/2, n/2, 0);
	copyMatrix(minus(add(p1,p5),add(p3,p7)), C, n/2, n/2, n/2);
	return C;
    }

    // Given a matrix of dimension n, break it into 4 block matrices.
    public static Quartet<int[][],int[][],int[][],int[][]> getBlockMatrix(int[][] A) {
	int n = A.length;
	int m = n/2;
	int[][] a = new int[m][m];
	int[][] b = new int[m][m];
	int[][] c = new int[m][m];
	int[][] d = new int[m][m];
	for (int i = 0; i < m; i++) {
	    for (int j = 0; j < m; j++) {
		a[i][j] = A[i][j];
		b[i][j] = A[i][j+m];
	    }
	}
	for (int i = m; i < n; i++) {
	    for (int j = 0; j < m; j++) {
		c[i-m][j] = A[i][j];
		d[i-m][j] = A[i][j+m];
	    }
	}
	return new Quartet<int[][],int[][],int[][],int[][]>(a,b,c,d);
    }

    // Copy over the content (upper left n*n part) from "A" to "B"
    // (upper left corner specified by "start_row" and "start_col").
    public static void copyMatrix(int[][] A, int[][] B, int n, int start_row, int start_col) {
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
		B[i+start_row][j+start_col] = A[i][j];
	    }
	}
    }

    // Sum of two matrices.
    public static int[][] add(int[][] A, int[][] B) {
	int n = A.length;
	int[][] C = new int[n][n];
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
		C[i][j] = A[i][j] + B[i][j];
	    }
	}
	return C;
    }

    // Substraction of two matrices.
    public static int[][] minus(int[][] A, int[][] B) {
	int n = A.length;
	int[][] C = new int[n][n];
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
		C[i][j] = A[i][j] - B[i][j];
	    }
	}
	return C;
    }

    public static int nextPowerOfTwo(int n) {
	if (n == 0) return 1;
	int shift = (int) Math.ceil(Math.log(n) / Math.log(2));
	return 1 << shift;
    }
}
