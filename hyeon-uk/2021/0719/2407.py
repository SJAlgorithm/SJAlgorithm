import math

n,m=input().split(" ")
n=int(n)
m=int(m)

up=math.factorial(n)
down=math.factorial(m)*math.factorial(n-m)

print(up//down)