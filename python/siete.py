def f(n,x,m):
	res=1
	while x>0:
		if x&1:
			res=(res*n)%m
		n=(n*n)%m
		x>>=1
	return res
while True:
	try:
		n=int(input())
		x=int(input())
		m=int(input())
		imp=f(n,x,m)
		print(imp)
		n=input()
	except EOFError:
		break
