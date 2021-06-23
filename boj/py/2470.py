N = int(input())
array = sorted(list(map(int, input().split())))

min_value = int(2e9)

start = 0
end = N - 1

while start < end:
    p1 = array[start]
    p2 = array[end]
    value = p1 + p2
    
    if abs(value) < min_value:
        min_value = abs(value)
        values = (p1, p2)

    if value > 0: end -= 1
    else: start += 1

print(values[0], values[1])