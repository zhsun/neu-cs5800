# 'k' specifies the range of key(A). [0...k].
def sort(A, k, key=lambda a: a):
    n = len(A)
    B = [0] * n
    C = [0] * (k+1)
    for i in range(n):
        C[key(A[i])] += 1
    for i in range(1,k+1):
        C[i] += C[i-1]
    for i in reversed(range(n)):
        pos = C[key(A[i])] - 1
        B[pos] = A[i]
        C[key(A[i])] -= 1
    return B
