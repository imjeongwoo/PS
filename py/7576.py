import sys
from collections import deque
M, N = map(int, input().split())
graph = [list(map(int, sys.stdin.readline().rstrip().split())) for _ in range(N)]
q = deque()
dx = [0, -1, 0, 1]
dy = [-1, 0, 1, 0]
for i in range(N):
    for j in range(M):
        if graph[i][j] == 1:
            q.append((i,j))

def solution():
    day = 0
    while q:
        y, x = q.popleft()
        for i in range(4):
            newX = x + dx[i]
            newY = y + dy[i]
            if 0 <= newX < M and 0 <= newY < N and graph[newY][newX] == 0:
                day = graph[y][x]
                graph[newY][newX] = day + 1
                q.append((newY, newX))
    return day

result = solution()

isTrue = False
for row in graph:
    if 0 in row:
        isTrue = True
        break
if isTrue: print(-1)
else: print(result)
