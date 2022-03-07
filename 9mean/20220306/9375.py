t = int(input())
for i in range(t):
    n = int(input())
    weardict = {}
    for j in range(n):
        wear = list(input().split())
        if wear[1] in weardict:
            weardict[wear[1]].append(wear[0])
        else:
            weardict[wear[1]] = [wear[0]]
    cnt = 1
    for k in weardict:
        cnt = cnt * (len(weardict[k]) + 1)
    print(cnt - 1)
