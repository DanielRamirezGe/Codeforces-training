	#include <bits/stdc++.h>
	using namespace std;
	#define maximo 8000005
	#define No_tiene -1
	#define Si_tiene 1
	#define aumentar 1
	#define disminuir 2	
	int tama,lineas;
	pair<int,int> arbol[maximo];
	pair<int,int> cambios[maximo]; 	
	void propagar(int i, int j, int p, int estado)
	{
		
			if(cambios[p].first!=No_tiene)
			{
				arbol[p].first=cambios[p].first;
				if(i!=j)
				{
					cambios[p<<1].first=cambios[p].first;
					cambios[(p<<1)+1].first=cambios[p].first;
				}
				cambios[p].first=No_tiene;
			}
			if(cambios[p].second!=No_tiene)
			{
				arbol[p].second=cambios[p].second;
				if(i!=j)
				{
					cambios[p<<1].second=cambios[p].second;
					cambios[(p<<1)+1].second=cambios[p].second;
				}
				cambios[p].second=No_tiene;
			}
		
	}
	void consultar(int i, int j, int p)
	{
		propagar(i, j, p, aumentar);
		propagar(i, j, p, disminuir);
		if(i==j)
		{
			printf("%d\n",arbol[p].first);
			return;
		}
		consultar(i, (i+j)/2, p<<1 );
		consultar( ((i+j)/2 )+1 ,j, (p<<1)+1);

	}

	void actualizar(int i, int j, int a, int b, int p, int valor, int estado)
	{
		propagar(i,j,p,estado);

		if(a>j or b<i)
			return;

		if(i>=a and j<=b)
		{
			if(estado==aumentar)
			{
				if(arbol[p].first>valor )
				{
					if(i!=j and arbol[p].second<valor)
					{
						actualizar(i, (i+j)/2, a, b, p<<1, valor, estado);
						actualizar(((i+j)/2)+1, j, a, b, (p<<1)+1, valor, estado);
						arbol[p].first=max(arbol[p<<1].first,arbol[(p<<1)+1].first);
						arbol[p].second=min(arbol[p<<1].second,arbol[(p<<1)+1].second);
					}
					return;
				}
				else
				{
					arbol[p].first=valor;
					arbol[p].second=valor;
					if(i!=j)
					{
						cambios[p<<1].second=valor;
						cambios[p<<1].first=valor;
						cambios[(p<<1)+1].second=valor;
						cambios[(p<<1)+1].first=valor;
					}
					return;
				}
			}
			else
			{
				if(arbol[p].second<valor )
				{
					if(i!=j and arbol[p].first>valor )
					{
						actualizar(i, (i+j)/2, a, b, p<<1, valor, estado);
						actualizar(((i+j)/2)+1, j, a, b, (p<<1)+1, valor, estado);
						arbol[p].first=max(arbol[p<<1].first,arbol[(p<<1)+1].first);
						arbol[p].second=min(arbol[p<<1].second,arbol[(p<<1)+1].second);
					}
					return;
				}
				else
				{
					arbol[p].second=valor;
					arbol[p].first=valor;
					if(i!=j)
					{
						cambios[p<<1].second=valor;
						cambios[p<<1].first=valor;
						cambios[(p<<1)+1].second=valor;
						cambios[(p<<1)+1].first=valor;
					}

					return;
				}
			}
		}
		if(i!=j)
		{
			actualizar( i, (i+j)/2, a, b, p<<1, valor, estado);
			actualizar( ((i+j)/2)+1, j, a, b, (p<<1)+1, valor, estado);
			arbol[p].first=max(arbol[p<<1].first,arbol[(p<<1)+1].first);
			arbol[p].second=min(arbol[p<<1].second,arbol[(p<<1)+1].second);
		}
	}
	int main()
	{
		scanf("%d %d",&tama,&lineas);
		memset(arbol,0,sizeof(arbol));
		memset(cambios,-1,sizeof(cambios));
		int estado, uno, dos, valor;
		tama--;
		for(int i=0; i<lineas; i++)
		{

			scanf("%d %d %d %d",&estado,&uno,&dos,&valor);
			if(estado==1)
				actualizar(0,tama,uno, dos, 1 , valor, aumentar );
			else
				actualizar(0, tama, uno, dos, 1, valor, disminuir);
		}
		consultar(0, tama, 1);
	}	