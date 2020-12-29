import math
c = 0
i = 1
n = int(input())
if n < 1:
    quit()
elif n == 1:
    print("It's prime number")
    quit()
m = int(math.sqrt(n))
while i <= m:
    if n % i == 0:
        c += 1
        print(c)
    elif c != 1:
        print("It's composite")
    else:
        print("It's prime number")
    
    i += 1
