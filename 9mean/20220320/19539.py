n = int(input())
tree = list(map(int, input().split()))
flag = 0
sum2 = 0
sum1 = sum(tree)
for x in tree:
    sum2 += x // 2
if sum1 % 3 == 0:
    if sum2 >= sum1 // 3:
        print("YES")
    else:
        print("NO")
else:
    print("NO")
