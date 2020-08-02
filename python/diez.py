while True:
	try:
		cad=""
		aux=input()
		cad+=aux
		while aux[len(aux)-1]!='#':
			#print(aux)
			aux=input()
			cad+=aux
			
			
		p=0
		pot=1
		
		for x in range(len(cad)-2,-1,-1):
			#print(x)
			if cad[x]=='1':
				p=(p+pot)%131071
			pot=(2*pot)%131071
		
		if p%131071==0:
			print("YES")
		else:
			print ("NO")
		#print (p)

	except EOFError:
		break