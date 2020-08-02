cases = int(input())
for x in range(cases):
	cad = input()
	dos=cad.split(' ')
	a=dos[0]
	b=dos[1]
	a_r=a[::-1]
	b_r=b[::-1]
	suma_uno=int(a_r)
	suma_dos=int(b_r)
	tot=suma_dos+suma_uno
	imp_u=str(tot)
	imp_u=imp_u[::-1]
	imp=int(imp_u)
	print (imp)