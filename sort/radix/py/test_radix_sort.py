import radix_sort
import unittest


class TestRadixSort(unittest.TestCase):
    def testGeneralCase(self):
        A = [465,321,474,355,123,
             777,919,134,221,756]
        A = radix_sort.sort(A, 3)
        expected = [123,134,221,321,355,
                    465,474,756,777,919]
        self.assertEqual(A, expected)


if __name__ == "__main__":
    unittest.main(verbosity=2)
