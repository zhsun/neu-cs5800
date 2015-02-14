import topological_sort
import unittest

# Helper function to test ordering.
def find_index(l, e):
    n = len(l)
    for i in range(n):
        if e == l[i]:
            return i
    return -1

class TopologicalSortTest(unittest.TestCase):
    def testLineGraph(self):
        g = {0:[1],
             1:[2],
             2:[3],
             3:[4],
             4:[]}
        l = topological_sort.sort(g)
        self.assertEqual(l, [0,1,2,3,4])

    def testTreeGraph(self):
        g = {0:[1,2],
             1:[3,4],
             2:[5],
             3:[],
             4:[],
             5:[]}
        l = topological_sort.sort(g)
        self.assertEqual(l[0], 0)
        self.assertLess(find_index(l,1), find_index(l,3))
        self.assertLess(find_index(l,1), find_index(l,4))
        self.assertLess(find_index(l,2), find_index(l,5))

    def testGeneralDAG(self):
        g = {0:[],
             1:[3,0],
             2:[0],
             3:[],
             4:[1,2],
             5:[6],
             6:[]}
        l = topological_sort.sort(g)
        self.assertLess(find_index(l,1), find_index(l,3))
        self.assertLess(find_index(l,1), find_index(l,0))
        self.assertLess(find_index(l,2), find_index(l,0))
        self.assertLess(find_index(l,4), find_index(l,1))
        self.assertLess(find_index(l,4), find_index(l,2))
        self.assertLess(find_index(l,5), find_index(l,6))


if __name__ == "__main__":
    unittest.main(verbosity=2)
