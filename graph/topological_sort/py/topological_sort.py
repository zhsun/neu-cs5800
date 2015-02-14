# Topological sort takes a DAG in adjacency list formant, and out put
# the topological order.
#
# g: graph in adjacency list
# return: list to hold vertices in topological order
def sort(g):
    visited = {}
    for u in g:
        visited[u] = False
    l = []
    for u in g:
        if not visited[u]:
            explore(g, u, visited, l)
    return list(reversed(l))

def explore(g, u, visited, l):
    visited[u] = True
    for v in g[u]:
        if not visited[v]:
            explore(g, v, visited, l)
    l.append(u)
