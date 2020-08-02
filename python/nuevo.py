import math
global p
p={}
n=int (input())
for i in range(1,n+1):
	cad=input()
	rec="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	for x in rec:
		p[x]=0
	for x in cad:
		p[x]+=1
	res=int(math.factorial(len(cad)))
	div=1
	va=p.values()
	for x in va:
		if x!=0:
			div*=math.factorial(x) 	
	imp=res//div
	print(f"Data set {i}: {imp}")

