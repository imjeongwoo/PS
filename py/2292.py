import sys

def sol(n):
    if n == 1:
        return 1
    result = 1
    qlry = 1+6*result
    while(True):
        if n <= qlry:
            return result+1
        else:
            result += 1
            qlry += 6*result

n = int(sys.stdin.readline())
print(sol(n))