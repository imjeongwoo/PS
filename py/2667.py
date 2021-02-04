import sys
n = int(input())
graph = [[0]*n for _ in range(n)]
visited = [[0]*n for _ in range(n)]
hList = []

for i in range(n):
    for j, h in enumerate(sys.stdin.readline().rstrip()):
        graph[i][j] = int(h)

""""
def dfs(x, y, g, v):
    v[x][y] = 1
    global nums
    nums += 1
    if y+1 < n:
        if g[x][y+1] and not v[x][y+1]:
            dfs(x, y+1, g, v)
    if x+1 < n:
        if g[x+1][y] and not v[x+1][y]:
            dfs(x+1, y, g, v)
    if y-1 >= 0:
        if g[x][y-1] and not v[x][y-1]:
            dfs(x, y-1, g, v)
    if x-1 >= 0:
        if g[x-1][y] and not v[x-1][y]:
            dfs(x-1, y, g, v)
"""
from collections import deque
q = deque()


def bfs(x, y, g, v):
    nums = 0
    q.append([x, y])
    v[x][y] = 1
    while q:
        x, y = q.popleft()
        nums += 1
        if y + 1 < n:
            if g[x][y + 1] and not v[x][y + 1]:
                q.append([x, y+1])
                v[x][y+1] = 1
        if x + 1 < n:
            if g[x + 1][y] and not v[x + 1][y]:
                q.append([x+1, y])
                v[x+1][y] = 1
        if y - 1 >= 0:
            if g[x][y - 1] and not v[x][y - 1]:
                q.append([x, y-1])
                v[x][y-1] = 1
        if x - 1 >= 0:
            if g[x - 1][y] and not v[x - 1][y]:
                q.append([x-1, y])
                v[x-1][y] = 1
    return nums


for i in range(n):
    for j in range(n):
        if graph[i][j] and not visited[i][j]:
            hList.append(bfs(i, j, graph, visited))
print(len(hList))
for _ in sorted(hList):
    print(_)