def permutation(A):
    if len(A) < 2: return [A]
    soln = []
    for i in range(len(A)):
        elem = A[i]
        remain = A[:i] + A[i+1:]
        remain_perm = permutation(remain)
        for perm in remain_perm:
            soln.append([elem] + perm)
    return soln
