import sys
global n


def checkValid(x, position):
    l = len(x)
    for i in range(position, n):

        if x == phoneList[i][:l]:
            return 1
    return 0


t = int(input())
for i in range(t):
    n = int(input())
    flag = 0
    idx = 0
    phoneList = []
    for j in range(n):
        num = input()
        phoneList.append(num)
    phoneList.sort()
    for k in phoneList:
        if checkValid(k, idx + 1) == 1:
            flag = 1
            print("NO")
            break
        idx += 1
    if flag == 0:
        print("YES")