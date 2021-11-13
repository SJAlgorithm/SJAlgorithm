def solution(distance, rocks, n):
    answer = 0
    rocks.sort()
    start = 0
    end = distance
    while start <= end:
        mid = (start + end) // 2  # mid는 가장 작은 거리임
        del_stone = 0  # 삭제된 돌 수
        loc_stone = 0  # 돌 위치
        for i in rocks:
            if i - loc_stone < mid:
                del_stone += 1
            else:
                loc_stone = i
            if del_stone > n:
                break;

        if del_stone > n:
            end = mid - 1
        else:
            answer = mid
            start = mid + 1

    return answer