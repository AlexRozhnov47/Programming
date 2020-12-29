<<<<<<< HEAD
<<<<<<< HEAD

def print_factorization(n: int)-> None:
  for i in range(2, int(n + 1)):
    if (n % i == 0):
        k = 0
        j = 1
        while (n % i == 0):
            n = n / i
            k+=1
        if (k == 1):
            print (i, "*")
        else:
             print (i, "^", k, "*")
        #print (i, k)
        
   #for j in range(1, i):
      #  if i * j == n:
            #return print_factorization(n)
        #    print(j, ' times ', i, ' equals ' , n)

n = int(input()) 
print_factorization(n)

=======

def print_factorization(n: int)-> None:
  for i in range(2, int(n + 1)):
    if (n % i == 0):
        k = 0
        j = 1
        while (n % i == 0):
            n = n / i
            k+=1
        if (k == 1):
            print (i, "*")
        else:
             print (i, "^", k, "*")
        #print (i, k)
        
   #for j in range(1, i):
      #  if i * j == n:
            #return print_factorization(n)
        #    print(j, ' times ', i, ' equals ' , n)

n = int(input()) 
print_factorization(n)

>>>>>>> d92fc76f9dbe538603ac9ce7dbb4c932a85dd9f5
=======

def print_factorization(n: int)-> None:
  for i in range(2, int(n + 1)):
    if (n % i == 0):
        k = 0
        j = 1
        while (n % i == 0):
            n = n / i
            k+=1
        if (k == 1):
            print (i, "*")
        else:
             print (i, "^", k, "*")
        #print (i, k)
        
   #for j in range(1, i):
      #  if i * j == n:
            #return print_factorization(n)
        #    print(j, ' times ', i, ' equals ' , n)

n = int(input()) 
print_factorization(n)

>>>>>>> d92fc76f9dbe538603ac9ce7dbb4c932a85dd9f5
