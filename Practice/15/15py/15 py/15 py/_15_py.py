
import random
i = 0
print("PC has generated new number")
m = random.randint(1,100)
while i < 6:
    print("Print yours.") 
    n = int(input())
    i += 1
    if n < m:
        print("Your number is smaller, than it should be") 
    if n > m:
        print("Your number is larger, than it should be")
    if n == m:
        break
if n == m:
    i = str(i)
    print("Congratulations! You found the number on this attempt")
    print(i)
if n != m:
    m = str(m)
    print("Sorry you lost. PC randomed that number. ")
    print(m)
