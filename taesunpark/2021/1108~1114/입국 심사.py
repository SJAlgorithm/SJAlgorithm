def solution(n, times):
    answer = 0
    start = 1
    end = max(times) * n # 최악의 경우 모든 사람이 젤 느린 곳으로 가서 시간이 늦어지는 경우

    while start <= end:
        mid = (start + end) // 2
        people = 0
        for i in times:
            people += mid // i
            if people >= n:     # 최대 사람 수가 넘을 경우
                break

        if people >= n:
            answer = mid
            end = mid - 1
        else:
            start = mid + 1

    return answer