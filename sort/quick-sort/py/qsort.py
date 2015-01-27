def qsort(A):
    qsort_rec(A, 0, len(A)-1)

def qsort_rec(A, low, high):
    if not A or low >= high:
        return
    pivot_pos = partition(A, low, high)
    qsort_rec(A, low, pivot_pos-1)
    qsort_rec(A, pivot_pos+1, high)

def partition(A, low, high):
    pivot = A[high]
    i = low - 1
    for cur in range(low, high):
        if A[cur] <= pivot:
            i = i + 1
            A[i], A[cur] = A[cur], A[i]
    i = i + 1
    A[i], A[high] = A[high], A[i]
    return i
