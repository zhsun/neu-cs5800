import heapsort
import unittest


class HeapsortTest(unittest.TestCase):
    def testSingleElem(self):
        A = [1]
        heapsort.sort(A)
        self.assertEqual(A, [1])

    def testGeneralCase(self):
        A = [3,2,6,5,1,8,7,9,4,10]
        heapsort.sort(A)
        self.assertEqual(A, [1,2,3,4,5,6,7,8,9,10])


if __name__ == "__main__":
    unittest.main(verbosity=2)
