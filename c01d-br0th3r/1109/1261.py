import sys
import heapq
input = sys.stdin.readline


def isRange(y, x):
    if y >= 0 and y < n and x >= 0 and x < m:
        return True
    else:
        return False


def bfs(arr, visited):
    pq = []
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    heapq.heappush(pq, (0, 0, 0))
    while pq:
        cnt, cy, cx = heapq.heappop(pq)
        visited[cy][cx] = True
        if cy == n-1 and cx == m-1:
            print(cnt)
            return
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if isRange(ny, nx):
                if not visited[ny][nx]:
                    visited[ny][nx] = True
                    if arr[ny][nx] == 0:
                        heapq.heappush(pq, (cnt, ny, nx))
                    else:
                        heapq.heappush(pq, (cnt+1, ny, nx))


m, n = map(int, input().split())
miro = []
visited = [[False] * m for _ in range(n)]
for _ in range(n):
    tmp = input()[:-1]
    miro.append([int(i) for i in tmp])
bfs(miro, visited)

