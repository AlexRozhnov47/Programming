
from math import sqrt
a = int(input())
b = int(input())
c = int(input())
D = b*b - 4*a*c
if D > 0:
    d = sqrt(D)
    x1 = (-1*b + d) / 2 * a
    x2 = (-1*b - d) / 2 * a
    print(x1)
    print(x2)
elif D == 0:
    x = -b / 2 *a
    print(x)
elif D < 0:
    print("Program stop")
else :
    print("You made mistake")