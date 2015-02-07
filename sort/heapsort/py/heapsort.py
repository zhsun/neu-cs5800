import data_structure.heap.py.heap as heap

def sort(A):
    heap.heap_make(A)
    i = len(A)
    while i > 0:
        heap.heap_delete(A, i)
        i = i - 1
