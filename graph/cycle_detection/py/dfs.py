WHITE = 0
GREY = 1
BLACK = 2

def has_cycle(g):
    color = {}
    for vertex in g:
        color[vertex] = WHITE
    for vertex in g:
        if color[vertex] == WHITE:
            if dfs(g, vertex, color):
                return True
    return False

def dfs(g, vertex, color):
    color[vertex] = GREY
    for u in g[vertex]:
        if color[u] == GREY:
            return True
        if color[u] == WHITE:
            if dfs(g, u, color):
                return True
    color[vertex] = BLACK
    return False
