import sys


def checkPrime(x):
    cnt = 0
    for i in range(2, x + 1):
        if x % i == 0:
            cnt += 1
    if cnt == 1:
        return 1
    else:
        return 0


n = int(input())
numList = list(map(int, sys.stdin.readline().split()))
res = 0
for x in numList:
    if checkPrime(x) == 1:
        res += 1
print(res)
