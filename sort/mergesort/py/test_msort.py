import msort
import unittest


class MSortTest(unittest.TestCase):
    def testMergeNormalList(self):
        A = [1, 3, 5, 7, 9]
        B = [2, 4, 6]
        self.assertEqual(msort.merge(A,B),
                         [1,2,3,4,5,6,7,9])

    def testMergeEmptyList(self):
        A = []
        B = [1, 2, 3]
        self.assertEqual(msort.merge(A,B),
                         [1,2,3])

    def testMSortNormalList(self):
        A = [3,5,7,1,3,6,7]
        self.assertEqual(msort.msort(A),
                         [1,3,3,5,6,7,7])

    def testMSortEmptyList(self):
        self.assertEqual(msort.msort([]), [])


if __name__ == "__main__":
    unittest.main(verbosity=2)
