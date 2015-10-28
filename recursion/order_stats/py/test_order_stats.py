import order_stats
import unittest


class OrderStatsTest(unittest.TestCase):
    def testFirst(self):
        A = [5,7,2,1,4,9,8,3,6]
        self.assertEqual(order_stats.kth(A, 1), 1)

    def testMiddle(self):
        A = [5,7,2,1,4,9,8,3,6]
        self.assertEqual(order_stats.kth(A, 5), 5)

    def testLast(self):
        A = [5,7,2,1,4,9,8,3,6]
        self.assertEqual(order_stats.kth(A, 9), 9)

    def testOutOfBound(self):
        A = [5,7,2,1,4,9,8,3,6]
        self.assertEqual(order_stats.kth(A, 10), None)


if __name__ == "__main__":
    unittest.main(verbosity=2)
