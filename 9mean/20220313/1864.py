numDict = {
    "-": 0,
    '\\': 1,
    "(": 2,
    "@": 3,
    "?": 4,
    ">": 5,
    "&": 6,
    "%": 7,
    "/": -1
}
while (1):
    a = list(input())
    if a[0] == '#':
        break
    a.reverse()
    k = 1
    res = 0
    for x in a:
        res += numDict[x] * k
        k *= 8
    print(res)
