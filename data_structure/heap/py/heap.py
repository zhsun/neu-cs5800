def heap_make(A, cmp = lambda a,b: a < b):
    i = len(A) / 2 - 1
    while i >= 0:
        heapify(A, len(A), i, cmp)
        i = i - 1


def heap_insert(A, heap_size, value, cmp = lambda a,b: a < b):
    A[heap_size] = value
    i = heap_size
    while has_parent(i) and not cmp(A[i], A[parent(i)]):
        A[i], A[parent(i)] = A[parent(i)], A[i]
        i = parent(i)


def heap_delete(A, heap_size, cmp = lambda a,b: a < b):
    A[0], A[heap_size-1] = A[heap_size-1], A[0]
    heapify(A, heap_size-1, 0, cmp)


# helper functions
def parent(pos):
    return (pos - 1) / 2

def left(pos):
    return 2 * pos + 1

def right(pos):
    return 2 * pos + 2

def has_parent(pos):
    return pos != 0

def has_left(pos, heap_size):
    return left(pos) < heap_size

def has_right(pos, heap_size):
    return right(pos) < heap_size

def heapify(A, heap_size, pos, cmp = lambda a,b: a < b):
    largest = pos
    if has_left(pos, heap_size) and not cmp(A[left(pos)], A[largest]):
        largest = left(pos)
    if has_right(pos, heap_size) and not cmp(A[right(pos)], A[largest]):
        largest = right(pos)
    if largest != pos:
        A[largest], A[pos] = A[pos], A[largest]
        heapify(A, heap_size, largest, cmp)
