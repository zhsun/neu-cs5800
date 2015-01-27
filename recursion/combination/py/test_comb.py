import comb
import unittest


class CombinationTest(unittest.TestCase):
    def testZeroElem(self):
        self.assertEqual(comb.combination([]), 
                         [[]])

    def testSingleElem(self):
        self.assertEqual(comb.combination([1]),
                         [[], [1]])

    def testGeneralCase(self):
        combs = comb.combination([1,2,3])
        self.assertEqual(len(combs), 8)
        self.assertIn([], combs)
        self.assertIn([1], combs)
        self.assertIn([2], combs)
        self.assertIn([3], combs)
        self.assertIn([1,2], combs)
        self.assertIn([1,3], combs)
        self.assertIn([2,3], combs)
        self.assertIn([1,2,3], combs)


if __name__ == "__main__":
    unittest.main(verbosity=2)
