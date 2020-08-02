global fibo
maxi= 109
fibo=[0]*maxi
fibo[0]=1
fibo[1]=2
for x in range(2,len(fibo)):
	fibo[x]=fibo[x-1]+fibo[x-2]
ban=1
while True:
	try:
		if ban==0:
			print()
		ban=0
		a=input()
		b=input()
		uno=0
		dos=0
		a=a[::-1]
		b=b[::-1]
		for x in range(0, len(a)):
			if a[x]=='1':
				#print(f"  {fibo[x]}")
				uno+=fibo[x]
		##print()
		for x in range(0, len(b)):
			if b[x]=='1':
				##print(f"  {fibo[x]}")
				dos+=fibo[x]
		imp=""
		res=uno + dos
		for x in range(len(fibo)-1, -1, -1):
			#print(f"{res}  {fibo[x]}")
			if res>=fibo[x]:
				imp=imp+"1"
				res-=fibo[x]
			else:
				imp=imp+"0"
		
		im=int(imp)
		
		print (im)
		b=input()
	except EOFError:
		break



