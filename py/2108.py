import sys
from collections import Counter
def getAverage(arr, N):
    return round(sum(arr) / N)

def getMedian(arr, N):
    arr.sort()
    return arr[N//2]

def range_(arr, N):
    return arr[N-1] - arr[0]

def mostFreq(arr, N):
    freq = Counter(arr).most_common()
    if N>1:
        if freq[0][1] == freq[1][1]: return freq[1][0]
        else: return freq[0][0]
    else: return freq[0][0]

def solution(arr, N):
    print(getAverage(arr, N))
    print(getMedian(arr, N))
    print(mostFreq(arr, N))
    print(range_(arr, N))

N = int(sys.stdin.readline())
arr = []
for _ in range(N):
  arr.append(int(sys.stdin.readline()))
solution(arr, N)
