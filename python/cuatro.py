global dos
global uno
maxi=1009
dos=[0]*maxi
uno=[0]*maxi
uno[0]=0
dos[0]=1
for x in range (1, len(uno)):
	uno[x]=dos[x-1]
	dos[x]=uno[x-1]+dos[x-1]

while True:
	try:
		n=int(input())
		print(uno[n]+dos[n])
	except EOFError:
		break
