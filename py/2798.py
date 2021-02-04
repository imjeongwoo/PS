from itertools import combinations
N, M = map(int, input().split())
arr = list(map(int, input().split()))
maxNum = 0

for _ in combinations(arr, 3):
    s = sum(_)
    if maxNum < s <= M:
        maxNum = s
print(maxNum)