from math import sqrt
a = int(input())
b = int(input())
c = int(input())
x1 = int(input())
x2 = int(input())
x3 = int(input())
y1 = int(input())
y2 = int(input())
y3 = int(input())
p = (a+b+c)/2
prs = (p*(p-a)*(p-b)*(p-c))
s1 = sqrt(prs)
print(s1);
prs1 = (x1*(y2-y3)+x2*(y3-y1)+x3*(y3-y2))
s2 = sqrt(prs1)
print(s2);
