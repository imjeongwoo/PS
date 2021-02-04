from collections import deque

def dfs(n):
    visited[n-1] = 1
    print(n, end=' ')
    for i in lines[n-1]:
        if not visited[i-1]:
            dfs(i)

def bfs(n):
    q = deque([n])
    visited[n-1] = 1
    while q:
        n = q.popleft()
        print(n, end=' ')
        for i in lines[n-1]:
            if not visited[i-1]:
                q.append(i)
                visited[i-1] = 1

N, M, V = map(int, input().split())
visited = [0] * N
lines = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    if b not in lines[a-1]:
        lines[a-1].append(b)
        lines[a-1].sort()
    if a not in lines[b-1]:
        lines[b-1].append(a)
        lines[b-1].sort()
dfs(V)
visited = [0] * N
print()
bfs(V)