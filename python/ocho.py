import math
global uno
maxi=10
uno=[0]*maxi
a=int(input())
while a!=0:
	b=int(math.factorial(a))
	for x in range (0,10):
		uno[x]=0
	while b>0:
		uno[b%10]+=1
		b//=10
	print(f"{a}! --")
	print('{:>6}'.format('(0)')+"{:5d}".format(uno[0])+'{:>7}'.format('(1)')+"{:5d}".format(uno[1])+'{:>7}'.format('(2)')+"{:5d}".format(uno[2])+'{:>7}'.format('(3)')+"{:5d}".format(uno[3])+'{:>7}'.format('(4)')+"{:5d}".format(uno[4]))
	print('{:>6}'.format('(5)')+"{:5d}".format(uno[5])+'{:>7}'.format('(6)')+"{:5d}".format(uno[6])+'{:>7}'.format('(7)')+"{:5d}".format(uno[7])+'{:>7}'.format('(8)')+"{:5d}".format(uno[8])+'{:>7}'.format('(9)')+"{:5d}".format(uno[9]))
	a=int(input())