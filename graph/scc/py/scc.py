def scc(g):
    to = topological_order(g)
    return cc(g, to)


def topological_order(g):
    l = []
    visited = {}
    for u in g.keys():
        visited[u] = False
    for u in g.keys():
        if not visited[u]:
            topological_dfs(g, u, visited, l)
    return l

def topological_dfs(g, u, visited, l):
    visited[u] = True
    for v in g[u]:
        if not visited[v]:
            topological_dfs(g, v, visited, l)
    l.append(u)

def cc(g, vertex_order):
    c = {}
    cnt = 0
    visited = {}
    for u in vertex_order:
        visited[u] = False
    for u in vertex_order:
        if not visited[u]:
            c[u] = cnt
            cc_dfs(g, u, visited, c)
            cnt += 1
    return c

def cc_dfs(g, u, visited, c):
    visited[u] = True
    for v in g[u]:
        if not visited[v]:
            c[v] = c[u]
            cc_dfs(g, v, visited, c)
