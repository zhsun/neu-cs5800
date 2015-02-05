import math

def strassen(A, B):
    n = len(A)
    # Make the size power of two, so we don't need to deal with odd
    #cases in recursion.
    m = next_power_of_two(n)
    largeA = init_matrix(m)
    copy_matrix(A, largeA, n, 0, 0)
    largeB = init_matrix(m)
    copy_matrix(B, largeB, n, 0, 0)
    largeC = strassen_rec(largeA, largeB)
    C = init_matrix(n)
    copy_matrix(largeC, C, n, 0, 0)
    return C

def strassen_rec(A, B):
    n = len(A)
    C = init_matrix(n)
    if n == 1: 
        C[0][0] = A[0][0] * B[0][0]
        return C
    a,b,c,d = get_block_matrix(A)
    e,g,f,h = get_block_matrix(B)
    # Calculate p1 to p7.
    p1 = strassen_rec(a, minus(g,h))
    p2 = strassen_rec(add(a,b), h)
    p3 = strassen_rec(add(c,d), e)
    p4 = strassen_rec(d, minus(f,e))
    p5 = strassen_rec(add(a,d), add(e,h))
    p6 = strassen_rec(minus(b,d), add(f,h))
    p7 = strassen_rec(minus(a,c), add(e,g))
    # Use p1 to p7 to reconstruct the product matrix.
    copy_matrix(minus(add(add(p4,p5),p6),p2), C, n/2, 0, 0)
    copy_matrix(add(p1,p2), C, n/2, 0, n/2)
    copy_matrix(add(p3,p4), C, n/2, n/2, 0)
    copy_matrix(minus(add(p1,p5),add(p3,p7)), C, n/2, n/2, n/2)
    return C

# Given a matrix of dimension n, break it into 4 block matrices.
def get_block_matrix(A):
    n = len(A)
    a = init_matrix(n/2)
    b = init_matrix(n/2)
    c = init_matrix(n/2)
    d = init_matrix(n/2)
    for r in range(n/2):
        a[r][:] = A[r][:n/2]
        b[r][:] = A[r][n/2:]
    for r in range(n/2,n):
        c[r-n/2][:] = A[r][:n/2]
        d[r-n/2][:] = A[r][n/2:]
    return (a,b,c,d)

# Copy over the content (upper left n*n part) from "A" to "B" (upper
# left corner specified by "start_row" and "start_col").
def copy_matrix(A, B, n, start_row, start_col):
    for r in range(n):
        for c in range(n):
            B[r+start_row][c+start_col] = A[r][c]

# Return sum of two matrices.
def add(A, B):
    n = len(A)
    C = init_matrix(n)
    for r in range(n):
        for c in range(n):
            C[r][c] = A[r][c] + B[r][c]
    return C

# Return subtraction of two matrices.
def minus(A, B):
    n = len(A)
    C = init_matrix(n)
    for r in range(n):
        for c in range(n):
            C[r][c] = A[r][c] - B[r][c]
    return C

# Return a matrix with all zero entries.
def init_matrix(n):
    return [[0 for c in range(n)] for r in range(n)]

def next_power_of_two(n):
    if n == 0: return 1
    return int(math.pow(2, math.ceil(math.log(n,2))))
