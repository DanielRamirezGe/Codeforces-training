import math
import string
def n_k( n, k):
	a=0
	for x in range(1, k+1):
		a+=math.log(n-x+1,10)
	b=0
	for x in range(1,k+1):
		b+=math.log(x,10)
	return a-b

while True:
	try:
		a=input()
		b=a.split(" ")
		n=b[0]
		k=b[1]
		n=int(n)
		k=int(k)
		if k<n-1:
			res=n_k(n,k)
		else:
			res=n_k(n,n-k)
		res=int(res)
		res+=1
		print(res)
	except EOFError:
		break