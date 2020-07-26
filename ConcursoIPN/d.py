mod = 10**9 + 7
def gauss(n,mod):
    return n*(n+1) % mod
 
n = int(input())
aux = 0
if n == 1:
    print(1)
elif n == 2:
    print(2)
elif n == 3:
    print(4)
elif n == 4:
    print(6)
 
else:
    n -= 2
    ans = 0
    antes = 2
    ite = 0
 
    for i in range(2,n):
        if(aux  > n): #si antes ya se paso rompe
            break
        ans = antes + (2*i*i)%mod
        #antes = ans
        aux += (2*i) % mod
    
        tot = antes % mod
        #print(ans,antes,i)
    
        antes = ans
        ite = i
    resto = ((n - gauss(ite-1,mod) + 2 + mod) % mod)* ite % mod
    print((tot+resto)%mod)