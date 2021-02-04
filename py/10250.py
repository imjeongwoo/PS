def solution(h, w, n):
    floor = n % h
    if floor == 0:
        floor = h
        ho = int(n /h)
    else:
        ho = int(n / h) + 1
    if ho < 10: floor *= 10
    return str(floor) + str(ho)

import sys
t = int(sys.stdin.readline())
for i in range(t):
    lst = list(map(int, sys.stdin.readline().split()))
    print(solution(lst[0], lst[1], lst[2]))