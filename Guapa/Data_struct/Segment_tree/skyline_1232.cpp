#include <bits/stdc++.h>
using namespace std;
#define maximo 800005
#define fin 100001
#define No_tiene -1
pair <int,int> arbol[maximo];
pair <int,int> cambios[maximo];
long long suma=0;
void propagar(int i, int j, int p)
{
	if(cambios[p].first!=No_tiene )	
	{
		if(arbol[p].first<cambios[p].first)
		{
			if(arbol[p].first<cambios[p].second)
			{
				arbol[p].first=cambios[p].first;
				arbol[p].second=cambios[p].second;
			}
			else
			{
				arbol[p].second=arbol[p].first;
				arbol[p].first=cambios[p].first;
			}
		}
		else
		{
			if(arbol[p].second<cambios[p].first  )
				arbol[p].second=cambios[p].first;
			else
			{
				if(arbol[p].second<cambios[p].second)
					arbol[p].second=cambios[p].second;
			}
		}
		if(i!=j)
		{
			cambios[p<<1].first=arbol[p].first;
			cambios[p<<1].second=arbol[p].second;
			cambios[(p<<1)+1].first=arbol[p].first;
			cambios[(p<<1)+1].second=arbol[p].second;
		}
		cambios[p].first=No_tiene;
		cambios[p].second=No_tiene;
	}
}
void consutar(int i, int j, int p)
{
	propagar(i,j,p);
	if(i==j)
	{
		//cout<<i<<"  "<<arbol[p].first<<" "<<arbol[p].second<<endl;
		suma+=arbol[p].second;
		return;
	}
	consutar(i, (i+j)/2, p<<1);
	consutar(((i+j)/2)+1, j, (p<<1)+1);
}
void actualizar(int i, int j, int a, int b, int p, int valor)
{
	propagar(i, j, p);
	if(i>b or j<a)
		return;
	if(i>=a and j<=b)
	{
		//cout<<i<<" "<<j<<" "<<p<<" "<<valor<<endl;
		//cout<<arbol[p].first<<" "<<arbol[p].second<<endl;
		if(valor>arbol[p].first)
		{
			arbol[p].second=arbol[p].first;
			arbol[p].first=valor;
			if(i!=j)
			{
				cambios[p<<1].first=valor;
				cambios[p<<1].second=arbol[p].second;
				cambios[(p<<1)+1].first=valor;
				cambios[(p<<1)+1].second=arbol[p].second;
			}
			//cout<<arbol[p].first<<" "<<arbol[p].second<<endl;
			return;
		}
		else
		{
			if(valor>arbol[p].second)
			{
				arbol[p].second=valor;
				if(i!=j)
				{
					cambios[p<<1].first=arbol[p].first;
					cambios[(p<<1)+1].first=arbol[p].first;
					cambios[p<<1].second=valor;
					cambios[(p<<1)+1].second=valor;
				}
			}
			//cout<<arbol[p].first<<" "<<arbol[p].second<<endl;
			return;
		}
	}
	if(i!=j)
	{	
		actualizar(i, (i+j)/2, a, b, p<<1, valor);
		actualizar(((i+j)/2)+1, j, a, b, (p<<1)+1, valor);
		arbol[p].first=min(arbol[p<<1].first, arbol[(p<<1)+1].first);
		arbol[p].second=min(arbol[p<<1].second, arbol[(p<<1)+1].second);
	}
}
int main()
{
	int cases, lines,valor;
	cin>>cases;
	int a,b;
	vector< pair< int, pair<int,int> > > vec;
	for(int i=0; i<cases; i++)
	{
		memset(arbol,0,sizeof(arbol));
		memset(cambios,-1,sizeof(cambios));
		cin>>lines;
		int min=maximo; int maxi=0;
		vec.clear();
		for(int j=0; j<lines; j++)
		{
			cin>>a>>b>>valor;
			if(a<min)
				min=a;
			if(b>maxi)
				maxi=b;
			vec.push_back({valor , {a,b} });
		}
		sort(vec.begin(), vec.end());
		for(int i=0; i<vec.size(); i++)
			actualizar(0, fin-1, vec[i].second.first, vec[i].second.second-1, 1, vec[i].first);
		suma=0;	
		consutar(0, fin-1, 1);
		cout<<suma<<endl;
	}
}