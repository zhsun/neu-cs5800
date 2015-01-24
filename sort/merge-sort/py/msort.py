def merge(A, B):
    C = []
    i = 0
    j = 0
    while i < len(A) and j < len(B):
        if A[i] < B[j]:
            C.append(A[i])
            i += 1
        else:
            C.append(B[j])
            j += 1
    C += A[i:]
    C += B[j:]
    return C

def msort(A):
    if len(A) < 2:
        return A[:]
    m = len(A) / 2
    left = A[:m]
    right = A[m:]
    sorted_left = msort(left)
    sorted_right = msort(right)
    return merge(sorted_left, sorted_right)
