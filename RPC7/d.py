t = int(input())
lista = []
while t > 0:
    n,k = map(int, input().split())
    lista = list(map(int,input().split()))
    #print(lista)
    piv = lista[0]
    suma = 0
    for i in range(1,k):
        if piv == lista[i]:
            suma += 1
        elif piv < lista[i]:
            suma += min(lista[i]-piv-1, n+piv-lista[i]+1)
        else:
            suma += min(piv-lista[i]+1,n+lista[i]-piv-1)
        
        piv=lista[i];
    print(suma)
    t-=1