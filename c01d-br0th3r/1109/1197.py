import sys
import heapq
input = sys.stdin.readline


def prim(graph, start):
    visited = [False] * (v+1)
    pq = []
    visited[start] = True
    for i in range(len(graph[start])):
        nv, nx = graph[start][i]
        heapq.heappush(pq, (nv, nx))
    ret = 0
    while pq:
        dist, current = heapq.heappop(pq)
        if visited[current]:
            continue
        visited[current] = True
        ret += dist
        for i in range(len(graph[current])):
            nd, nx = graph[current][i]
            heapq.heappush(pq, (nd, nx))

    return ret


v, e = map(int, input().split())
graph = [[] * (v+1) for _ in range(v+1)]
for _ in range(e):
    src, dest, val = map(int, input().split())
    graph[src].append((val, dest))
    graph[dest].append((val, src))

print(prim(graph, 1))

