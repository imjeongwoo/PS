import sys


def solution(k, n):
    for i in range(1, k + 1):
        for j in range(1, n):
            apart[i][j] = apart[i - 1][j] + apart[i][j - 1]
    return apart[k][n - 1]


apart = [[0] * 14 for _ in range(15)]
for i in range(15):
    if i == 0:
        for j in range(14):
            apart[0][j] = j + 1
    else:
        apart[i][0] = 1
t = int(sys.stdin.readline())
for i in range(t):
    k = int(sys.stdin.readline())
    n = int(sys.stdin.readline())
    print(solution(k, n))
# 9     11 66
# 8     10 55
# 7     9  45
# 6     8  36
# 5     7  28
# 4  1  6  21
# 3  1  5  15   25
# 2  1  4  10   20 25
# 1  1  3  6   10 1 5 21
# 0  1  2  3   4 5 6
