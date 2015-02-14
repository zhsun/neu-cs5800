import dfs
import unittest


class DfsTest(unittest.TestCase):
    def testGraphWithNoEdges(self):
        g = {0:[],
             1:[],
             2:[],
             3:[],
             4:[]}
        self.assertFalse(dfs.has_cycle(g))

    def testCycleGraph(self):
        g = {0:[1],
             1:[2],
             2:[3],
             3:[4],
             4:[0]}
        self.assertTrue(dfs.has_cycle(g))

    def testTreeGraph(self):
        g = {0:[1,2],
             1:[3,4],
             2:[5],
             3:[],
             4:[],
             5:[]}
        self.assertFalse(dfs.has_cycle(g))

    def testDAG(self):
        g = {0:[1,2],
             1:[3,4],
             2:[3,4],
             3:[],
             4:[3]}
        self.assertFalse(dfs.has_cycle(g))

    def testGeneralCase(self):
        g = {0:[1,2,4],
             1:[],
             2:[1,3],
             3:[0],
             4:[2,3]}
        self.assertTrue(dfs.has_cycle(g))


if __name__ == "__main__":
    unittest.main(verbosity=2)
