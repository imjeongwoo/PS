import sys, heapq

N = int(input())
array = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
array = sorted(array, key=lambda x: x[0])

heap = []
for i in range(N):
    if heap and array[i][0] >= heap[0]:
        heapq.heappop(heap)
    heapq.heappush(heap, array[i][1])
print(len(heap))