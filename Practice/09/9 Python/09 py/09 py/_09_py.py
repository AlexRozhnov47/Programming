print("Type first time")
h = int(input())
m = int(input())
print("Type second time")
H = int(input())
M = int(input())
MI = M + 15

if ((h <= 0)&(H < 24)):
    print("You do the right thing")
else:
    print("The hour does not match");
if ((m <= 0)&(M < 60)):
    print("You also doing nice")
else:
     print("The minuite does not match");
if ((h == H)&(m <= MI)):
    print("They will meet")
else:
    print("They would not");
