import heapq as hq
import sys

n = int(input())
heap = []
for i in range(n):
    num = int(sys.stdin.readline())
    if num == 0:
        if len(heap) >= 1:
            print(-1 * hq.heappop(heap))
        else:
            print(0)
    else:
        hq.heappush(heap, (-num))
