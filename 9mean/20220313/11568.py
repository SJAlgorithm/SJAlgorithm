global lis


def binarySearch(l, r, x):
    while l <= r:
        mid = (l + r) // 2
        if lis[mid] < x:
            l = mid + 1
        else:
            r = mid - 1
    return r


n = int(input())
card = list(map(int, input().split()))
lis = []
lis.append(card[0])
j = 0
for i in range(1, n):
    if lis[j] < card[i]:
        lis.append(card[i])
        j += 1
    else:
        idx = binarySearch(0, j, card[i])
        lis[idx] = card[i]
print(len(lis))