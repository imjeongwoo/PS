def dfs(n, visited, comList):
    global virus
    visited[n] = 1
    virus += 1
    for i in comList[n]:
        if not visited[i]:
            dfs(i, visited, comList)
import sys
virus = -1
c = int(input())
n = int(input())
visited = [0]*(c+1)
comList = [[] for i in range(c+1)]
for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    if b not in comList[a]:
        comList[a].append(b)
    if a not in comList[b]:
        comList[b].append(a)
for i in comList: i.sort()
dfs(1, visited, comList)
print(virus)


