maxi=10009
global criba
criba=[0]*maxi
global primo
global acumulada
primo=[]
acumulada=[]
def c():
	criba[1]=1;
	criba[2]=1;
	primo.append(2)
	for x in range(3,len(criba), 2):
		if criba[x]==0:
			primo.append(x)
			for j in range(x*x, len(criba), x):
				criba[j]=1
		
n=int (input())
c()
acumulada.append(primo[0])
for x in range(1,len(primo)):
	acumulada.append(primo[x-1]+primo[x])
##for x in range(0,len(primo)):
#	print (f" {primo[x]}")

while n!=0:
	tot=0
	l=0
	r=0
	con=0
	while r<len(primo) and primo[l]<=n :
		#if n==3:
		#	print(f"   {tot} ")
		if tot<n:
			tot+=primo[r]
			r+=1
		elif tot>n:
			tot-=primo[l]
			l+=1
		else:
			tot+=primo[r]
			con+=1
			r+=1
	print(con)
	n=int(input())