import math
while True:
	try:
		p=input()
		arr=p.split(" ")
		uno=int(arr[0])
		dos=int(arr[1])
		n=int(math.factorial(uno))
		k=int(math.factorial(uno-dos))
		p=n//k
		while p%10==0:
			p//=10
		print(p%10)
	except EOFError:
		break