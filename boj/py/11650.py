import sys
N = int(input())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
arr.sort()
for lst in arr:
    print(lst[0], lst[1])