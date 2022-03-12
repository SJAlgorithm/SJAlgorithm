n = int(input())
m = int(input())
right = 0
cnt = 0
attackList = []
for i in range(m):
    x, y = map(int, input().split())
    attackList.append((x, y))
attackList.sort()
for x, y in attackList:
    if right < x:
        cnt += x - right
    if right < y:
        right = y
cnt += n - right
print(cnt)
