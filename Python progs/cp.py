N = int(input())
arr = []
for i in range(N):
    arr.append(list(map(int, input().split())) + [i + 1])

arr.sort()

res = []

min_y = 10**18

for x, y, i in arr[::-1]:
    if y < min_y:
        min_y = y
        res.append(i)
    
print(len(res))
print(*res[::-1])
