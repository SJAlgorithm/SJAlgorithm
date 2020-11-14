import sys
from collections import deque
input = sys.stdin.readline


def bfs(crack, visited):
    q = deque()
    q.append(0)
    visited[0] = 1
    while q:
        idx = q.popleft()
        if crack[idx][0] == T:
            return visited[idx] - 1
        cy, cx = crack[idx]
        for i in range(idx-1, 0, -1):
            if abs(crack[i][1] - cx) > 2:
                break
            if visited[i] == 0 and abs(crack[i][0] - cy) <= 2:
                visited[i] = visited[idx] + 1
                q.append(i)
        for i in range(idx+1, n+1):
            if abs(crack[i][1] - cx) > 2:
                break
            if visited[i] == 0 and abs(crack[i][0] - cy) <= 2:
                visited[i] = visited[idx] + 1
                q.append(i)
    return -1


n, T = map(int, input().split())
crack = [(0, 0)]
for _ in range(n):
    x, y = map(int, input().split())
    crack.append((y, x))
visited = [0] * len(crack)
crack = sorted(crack, key=lambda x: (x[1], x[0]))
print(bfs(crack, visited))

