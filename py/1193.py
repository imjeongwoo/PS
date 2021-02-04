def solution(x):
    if x == 1:
        return 1, 1

    count = 2
    compare = 1 + count
    while(x > compare):
        count += 1
        compare += count

    dif = compare - x
    if count%2 == 1:
        row = 1 + dif
        col = count - dif
    else:
        row = count - dif
        col = 1 + dif
    return row, col

import sys
x = int(sys.stdin.readline())
r, c = solution(x)
print(f'{r}/{c}')