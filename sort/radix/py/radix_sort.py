import sort.count.py.counting_sort as csort

# digits means the number of digits for ints in A.
def sort(A, digits):
    for i in range(digits):
        B = csort.sort(A, 9, lambda a: (a / 10 ** i) % 10)
        A = B
    return A
