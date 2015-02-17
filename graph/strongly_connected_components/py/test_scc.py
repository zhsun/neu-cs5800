import scc
import unittest


class SCCTest(unittest.TestCase):
    def testNoEdgeGraph(self):
        g = {0:[],
             1:[],
             2:[],
             3:[],
             4:[]}
        cc = scc.scc(g)
        self.assertNotEqual(cc[0], cc[1])
        self.assertNotEqual(cc[0], cc[2])
        self.assertNotEqual(cc[0], cc[3])
        self.assertNotEqual(cc[0], cc[4])
        self.assertNotEqual(cc[1], cc[2])
        self.assertNotEqual(cc[3], cc[4])

    def testTreeGraph(self):
        g = {0:[1,2],
             1:[3,4],
             2:[5],
             3:[],
             4:[],
             5:[]}
        cc = scc.scc(g)
        self.assertNotEqual(cc[0], cc[1])
        self.assertNotEqual(cc[0], cc[2])
        self.assertNotEqual(cc[0], cc[3])
        self.assertNotEqual(cc[0], cc[4])
        self.assertNotEqual(cc[0], cc[5])
        self.assertNotEqual(cc[1], cc[2])
        self.assertNotEqual(cc[3], cc[4])

    def testGeneralGraph(self):
        g = {0:[],
             1:[0,4],
             2:[1,5],
             3:[1],
             4:[1],
             5:[2],
             6:[4,7],
             7:[5,9],
             8:[6],
             9:[8]}
        cc = scc.scc(g)
        # 0 itself forms a cc.
        # 3 itself forms a cc.
        # 1 and 4 form a cc.
        # 2 and 5 form a cc.
        # 6, 7, 8, and 9 form a cc.
        self.assertEqual(cc[1], cc[4])
        self.assertEqual(cc[2], cc[5])
        self.assertEqual(cc[6], cc[7])
        self.assertEqual(cc[6], cc[8])
        self.assertEqual(cc[6], cc[9])
        # Check different cc are numbered differently.
        self.assertNotEqual(cc[0], cc[1])
        self.assertNotEqual(cc[0], cc[2])
        self.assertNotEqual(cc[0], cc[3])
        self.assertNotEqual(cc[0], cc[6])
        self.assertNotEqual(cc[1], cc[2])
        self.assertNotEqual(cc[1], cc[3])
        self.assertNotEqual(cc[1], cc[6])
        self.assertNotEqual(cc[2], cc[3])
        self.assertNotEqual(cc[2], cc[6])
        self.assertNotEqual(cc[3], cc[6])


if __name__ == "__main__":
    unittest.main(verbosity=2)
