import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a)
d = [0] * (n+1)
possible = True
for i in range(1, n+1):
    if d[i]:
        continue
    d[i] = 1
    q = deque()
    q.append(i)
    while q:
        current = q.popleft()
        for i in range(len(arr[current])):
            nx = arr[current][i]
            if d[nx]:
                if d[nx] == d[current]:
                    possible = False
                    break
            else:
                d[nx] = -d[current]
                q.append(nx)
if possible:
    print("1")
else:
    print("0")

