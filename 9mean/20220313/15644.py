# 엔과 엠 (10)
n, m = map(int, input().split(' '))
number = list(map(int, input().split(' ')))
number.sort()
array = []
result = []


def solve(level, index):
    if level == m:
        a = ' '.join(map(str, array))
        if a not in result:
            result.append(a)
            print(a)
        return

    for i in range(index, n):  #핵심 부분
        array.append(number[i])
        solve(level + 1, i + 1)
        array.pop()


solve(0, 0)
