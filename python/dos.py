import math
def test_prime(n):
    if (n==1):
        return False
    elif (n==2):
        return True;
    else:
        top=int(math.sqrt(n))
        top+=1
        for x in range(2,top):
            if(n % x==0):
          	  return False
        return True  
         
while True:
    try:
        uno=input()
        po=uno
        dos=po[::-1]
        uno=int(uno)
        dos=int(dos)
        ban=0
        if test_prime(uno)==True:
            ban+=2
        if test_prime(dos)==True:
            ban+=3
        if uno==dos:
        	ban-=3
        if ban==2 :
        	print(f"{po} is prime.")
        elif ban==5:
            print(f"{po} is emirp.")
        else:
        	print(f"{po} is not prime.")
            
    except EOFError:
        break