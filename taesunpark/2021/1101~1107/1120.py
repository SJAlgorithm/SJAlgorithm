front_str, back_str = input().split()
# output 최대 값 51 조건 명시
min_num = 51

for i in range(0, len(back_str)):
    # 두 문자열의 배열 요소 값이 다르면 증가 값 담는 변수
    diff_num = 0

    # 배열 할당 메모리 넘어가는 걸 방지하기 위한 조건문
    if len(back_str)-1 < len(front_str)-1 + i:
        break

    for j in range(0, len(front_str)):
        if front_str[j] != back_str[i + j]:
            diff_num += 1

    if min_num > diff_num:
        min_num = diff_num

print(min_num)