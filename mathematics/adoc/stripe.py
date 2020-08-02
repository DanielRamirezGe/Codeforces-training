import math
cases=int(input())
for x in range(0, cases):
	cad=input()
	dos=cad.split(' ')
	for x in range(0,len(dos)):
		dos[x]=int(dos[x])
	tam=dos[0]
	tam=int(tam)
	tot=dos[1]
	tot=int(tot)
	negros=0

	for x in range(2,len(dos)):
		num=int(dos[x])
		negros+=num
		#print(" x",negros)

	#print("res",res)
	res=negros+tot-1
	if(tot==0):
		print(1)
	elif(res>tam or res<0):
		print(0)
	else:
		n=tam-(negros+tot-1)
		#print("   ", n)
		k=tot+1
		# print("   ",n,"  ",nnegros,"  ",tam)
		# k=tot
		# print("   ",k)
		var=int(math.factorial(int(n+k-1))//(math.factorial(int(n+k-1-(k-1)))*math.factorial(int(k-1))))
		print(var)
		# imp=int(var)
		# print(imp)
