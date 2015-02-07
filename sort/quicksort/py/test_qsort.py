import qsort
import unittest


class QSortTest(unittest.TestCase):
    def testQSortNormalList(self):
        A = [3,5,7,1,3,6,7]
        qsort.qsort(A)
        self.assertEqual(A, [1,3,3,5,6,7,7])

    def testQSortEmptyList(self):
        A = []
        qsort.qsort(A)
        self.assertEqual(A, [])


if __name__ == "__main__":
    unittest.main(verbosity=2)
