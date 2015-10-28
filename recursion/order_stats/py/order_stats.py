def kth(A, k):
    return kth_rec(A, k, 0, len(A)-1)


def kth_rec(A, k, low, high):
    if low > high or high - low + 1 < k: return None
    pivot_pos = partition(A, low, high)
    pivot_rank = pivot_pos - low + 1
    if pivot_rank == k: return A[pivot_pos]
    if pivot_rank > k:
        return kth_rec(A, k, low, pivot_pos-1)
    return kth_rec(A, k-pivot_rank, pivot_pos+1, high)


def partition(A, low, high):
    assert low <= high
    pivot = A[high]
    i = low - 1
    for cur in range(low, high):
        if A[cur] < pivot:
            i += 1
            A[i], A[cur] = A[cur], A[i]
    i += 1
    A[i], A[high] = A[high], A[i]
    return i
