a, b, = float(input()), int(input())
 
def power(a,n):
    z, c, r, arr = 0, 1, 0, []
    if n > 1:
        while c < b:
            if b == 2:
                arr.append(a * a)
                r += arr[z]
            else:
                if c < 2:
                    arr.append(a * a)
                    r += arr[z]
                else:
                    arr.append(a)
                    r *= arr[z]
            c += 1
            z += 1
    else:
        r += a
    return r
 
print ( power(a,b), a**b)
