import counting_sort
import unittest


class TestCountingSort(unittest.TestCase):
    def testGeneralCase(self):
        A = [3,1,2,5,3,1,5,2,4]
        B = counting_sort.sort(A,5)
        self.assertEqual(B, [1,1,2,2,3,3,4,5,5])


if __name__ == "__main__":
    unittest.main(verbosity=2)
