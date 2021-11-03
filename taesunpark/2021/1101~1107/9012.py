num = int(input())

for i in range(0, num):
    # 입력 받을 전체 괄호
    all_stack_list = list(input())
    # 왼쪽 괄호 갯수 담을 변수
    left_stack_num = 0
    for j in all_stack_list:
        # 왼쪽 괄호면 +1, 오른쪽 괄호면 -1, 만약 오른쪽 괄호가 -1이면 해당 스택에 없는 데 접근한 것이므로 break
        if j == '(':
            left_stack_num += 1
        elif j == ')':
            left_stack_num -= 1
            if left_stack_num < 0:
                break
    if left_stack_num == 0:
        print("YES")
    else:
        print("NO")


