import heap
import unittest


class HeapTest(unittest.TestCase):
    def testMaxHeap(self):
        A = [1,3,2,6,4,5]
        heap.heap_make(A)
        self.assertEqual(A[0], 6)
        heap.heap_delete(A, len(A))
        self.assertEqual(A[0], 5)
        self.assertEqual(A[-1], 6)
        heap.heap_insert(A, len(A)-1, 7)
        self.assertEqual(A[0], 7)

    def testMinHeap(self):
        cmp = lambda a,b: a > b
        A = [1,3,2,6,4,5]
        heap.heap_make(A, cmp)
        self.assertEqual(A[0], 1)
        heap.heap_delete(A, len(A), cmp)
        self.assertEqual(A[0], 2)
        self.assertEqual(A[-1], 1)
        heap.heap_insert(A, len(A)-1, 0, cmp)
        self.assertEqual(A[0], 0)


if __name__ == "__main__":
    unittest.main(verbosity=2)

