from collections import deque

def solution(n, edge):
    answer = 0
    node = [[] * (n + 1) for _ in range(n + 1)]  # 리스트 생성

    # 양방향 연결
    for x1, x2 in edge:
        node[x1].append(x2)
        node[x2].append(x1)

    # 방문했는 지 확인
    visited = [(-1) for _ in range(n + 1)]

    # queue 생성 첫번째 요소는 시작 점, 두번째 요소는 count
    q = deque([[1, 0]])
    visited[1] = 0

    while q:
        nq, count = q.popleft()
        for i in node[nq]:
            if visited[i] == -1:
                q.append([i, count + 1])
                visited[i] = count + 1
    m = max(visited)

    for i in visited:
        if m == i:
            answer = answer + 1

    return answer
