import perm
import unittest


class PermutationTest(unittest.TestCase):
    def testZeroElem(self):
        self.assertEqual(perm.permutation([]), [])

    def testSingleElem(self):
        self.assertEqual(perm.permutation([1]),
                         [[1]])

    def testGeneralCase(self):
        self.assertEqual(perm.permutation([1,2,3]),
                         [[1,2,3], [1,3,2],
                          [2,1,3], [2,3,1],
                          [3,1,2], [3,2,1]])


if __name__ == "__main__":
    unittest.main(verbosity=2)
