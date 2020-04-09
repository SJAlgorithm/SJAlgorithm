# 7576 토마토

간단한 BFS 문제이지만 시작점이 여러 곳이라는 것이 다르다.

보통은 시작 좌표를 큐에 push하고 empty 전까지 돌리는데

이 친구는 모든 1의 좌표를 push하고 돌린다.

그 아이디어만 알고있다면 쉽게 풀 수 있는 문제

# 1759 암호 만들기

대가리 터질 뻔 했다.

중복되는 알파벳이 없고, 오름차순으로 출력하는 것이기 때문에 일단 정렬했다.

생각해보니 C 까지의 숫자 중에서 L 만큼의 부분수열을 만드는 문제랑 똑같았다.

케이스가 적고 시간제한이 2초이니 완전탐색으로 풀어도 여유로울 것 같아 dfs를 사용하기로 했다.

dfs 구현은, (-1, -1)에서 출발하여 for문으로 들어간다.

start 값에 1을 더해서 방문 체크, 재귀를 돈 후 방문 해제했다.

for문 시작을 start값으로 둔 이유는 인덱스가 커졌을 때, 이전 노드를 방문하여 중복이 발생할 수 있기 때문이다.

헷갈렸던 점은 처음에 dfs(0, 0)을 주어 재귀를 dfs(1, 1), dfs(1, 2)... 이런 식으로 돌아

첫 번째 인덱스가 백트래킹 되지 않았던 것이다. 시작을 dfs(-1, -1)로 두어 해결했다.

두 번째는 문제에 최소 한 개의 모음, 최소 두 개의 자음을 못봤다.

좀 더 효율적으로 풀 수 있었겠지만 시간이 촉박해서 그냥 다 검사했다.

케이스가 여유로웠기 때문에 가능했던 것 같다.

처음으로 풀이를 보지 않고 푼 백트래킹 문제라 zonna 기뻤다.