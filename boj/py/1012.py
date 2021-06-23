import sys
T = int(input())


def dfs(x, y, g, m, n):
    g[x][y] = 0
    if y + 1 < m:
        if g[x][y + 1]:
            dfs(x, y + 1, g, m, n)
    if x + 1 < n:
        if g[x + 1][y]:
            dfs(x + 1, y, g, m, n)
    if y - 1 >= 0:
        if g[x][y - 1]:
            dfs(x, y - 1, g, m, n)
    if x - 1 >= 0:
        if g[x - 1][y]:
            dfs(x - 1, y, g, m, n)


for _ in range(T):
    nums = 0
    M, N, K = map(int, sys.stdin.readline().split())
    graph = [[0]*M for i in range(N)]
    for _ in range(K):
        a, b = map(int, sys.stdin.readline().split())
        graph[b][a] = 1
    for a in range(N):
        for b in range(M):
            if graph[a][b]:
                dfs(a, b, graph, M, N)
                nums += 1
    print(nums, "\n")
