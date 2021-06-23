n = int(input())
result = 0
number = 0
for i in range(1, n):
   l = list(map(int, list(str(i))))
   result = i + sum(l)
   if result == n:
      number = i
      break
print(number)



