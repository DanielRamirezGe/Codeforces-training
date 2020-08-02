uno=input()
a=int(input())
b=int(input())
p=input()
pos=0
for x in range(0,len(p)):
	if p[x]=='*':
		pos=x
		break
for x in range(1,10):
	c=str(x)
	new = list(p)
	new[pos] = c[0]
	nuevo=''.join(new)
	aux=int(nuevo)
	if aux%a==0 and aux%b==0:
		print(x)
		break


	