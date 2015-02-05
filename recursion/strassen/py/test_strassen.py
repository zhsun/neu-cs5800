import strassen
import unittest


class StrassenTest(unittest.TestCase):
    def testNextPowerOfTwo(self):
        self.assertEqual(strassen.next_power_of_two(0), 1)
        self.assertEqual(strassen.next_power_of_two(1), 1)
        self.assertEqual(strassen.next_power_of_two(2), 2)
        self.assertEqual(strassen.next_power_of_two(3), 4)
        self.assertEqual(strassen.next_power_of_two(13), 16)

    def testAdd(self):
        A = [[1,2],[3,4]]
        B = [[1,1],[1,1]]
        expected = [[2,3],[4,5]]
        self.assertEqual(strassen.add(A,B), expected)

    def testMinus(self):
        A = [[1,2],[3,4]]
        B = [[1,1],[1,1]]
        expected = [[0,1],[2,3]]
        self.assertEqual(strassen.minus(A,B), expected)

    def testCopyMatrix(self):
        A = [[1,1],[2,2]]
        B = strassen.init_matrix(4)
        strassen.copy_matrix(A, B, len(A), 0, 0)
        expected = [[1,1,0,0],
                    [2,2,0,0],
                    [0,0,0,0],
                    [0,0,0,0]]
        self.assertEqual(B, expected)
        C = strassen.init_matrix(4)
        strassen.copy_matrix(A, C, len(A), 1, 1)
        expected = [[0,0,0,0],
                    [0,1,1,0],
                    [0,2,2,0],
                    [0,0,0,0]]
        self.assertEqual(C, expected)

    def testGetBlockMatrix(self):
        A = [[1,2],[3,4]]
        a,b,c,d = strassen.get_block_matrix(A)
        self.assertEqual(a, [[1]])
        self.assertEqual(b, [[2]])
        self.assertEqual(c, [[3]])
        self.assertEqual(d, [[4]])

    def testStrassenEven(self):
        A = [[1,1],[1,1]]
        B = [[1,2],[3,4]]
        expected = [[4,6],[4,6]]
        self.assertEqual(strassen.strassen(A,B), expected)

    def testStrassenOdd(self):
        A = [[1,2,3],[2,3,4],[3,4,5]]
        B = [[1,1,1],[1,1,1],[1,1,1]]
        expected = [[6,6,6],[9,9,9],[12,12,12]]
        self.assertEqual(strassen.strassen(A,B), expected)


if __name__ == "__main__":
    unittest.main(verbosity=2)
