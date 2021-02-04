import sys

N = int(input())
arr = []
for i in range(N):
   lst = list(map(int, sys.stdin.readline().split()))
   lst.append(1)
   arr.append(lst)

for i in range(0, N-1):
    for j in range(i+1, N):
        if arr[i][0] > arr[j][0] and arr[i][1] > arr[j][1]:
            arr[j][2] += 1
        elif arr[i][0] < arr[j][0] and arr[i][1] < arr[j][1]:
            arr[i][2] += 1
        else: pass

for i in arr:
    print(i[2], end=' ')