n = int(input())
numList = list(map(int, input().split()))
visited = [0] * 400001
cnt = 0
for i in range(n):
    for j in range(i):
        if visited[numList[i] - numList[j] + 200000] == 1:
            cnt += 1
            break
    for j in range(i + 1):
        visited[numList[i] + numList[j] + 200000] = 1
print(cnt)
