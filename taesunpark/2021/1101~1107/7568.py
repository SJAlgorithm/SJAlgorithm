num = int(input())
# 덩치 등수
rank_list = []
# 무게
weight_list = []
# 키
height_list = []

# 입력 값으로 리스트 세팅
for i in range(0, num):
    rank_list.append(int(1))
    a, b = input().split()
    weight_list.append(int(a))
    height_list.append(int(b))

#
for i in range(0, num-1):
    for j in range(i+1, num):
        # 키와 몸무게가 작으면 현재 i 의 rank를 늘려주고, 키와 몸무게 둘다 크면 상대방 rank를 늘려준다.
        if weight_list[i] < weight_list[j] and height_list[i] < height_list[j]:
            rank_list[i] += 1
        elif weight_list[i] > weight_list[j] and height_list[i] > height_list[j]:
            rank_list[j] += 1

for i in range(0, num):
    print(rank_list[i], end=" ")
