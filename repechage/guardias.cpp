#include <bits/stdc++.h>
using namespace std;
#define maxi 100009
vector<long long> mat[maxi];
long long padre[maxi];
int main()
{
	long long n,cost,a,b;
	cin>>n>>cost;
	long long inicio=-1;
	for(long long i=1; i<n; i++)
	{
		cin>>a>>b;
		if(inicio==-1)
			inicio=a;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	if(inicio==-1)
		inicio=1;
	queue <long long> cola, hojas;
	memset(padre, -1, sizeof(padre));
	cola.push(inicio);

	padre[inicio]=inicio;
	while(!cola.empty())
	{
		long long nodo=cola.front();
		cola.pop();
		bool ban=1;
		//cout<<" "<<nodo<<endl;
		for(auto x: mat[nodo])
		{
			if(padre[x]==-1)
			{
				padre[x]=nodo;
				cola.push(x);
				ban=0;
			}
		}
		if(ban)
			hojas.push(nodo);
	}
	map <long long,long long> mapa;
	long long con=0;
	while(!hojas.empty())
	{
		long long primer=hojas.front();
		hojas.pop();
		if(mapa[primer]==0)
		{
			int segundo=padre[primer];
			if(segundo!=primer )
			{
				
				for(auto x: mat[segundo])
					mapa[x]++;
				mapa[segundo]++;
				int tercero=padre[segundo];
				mapa[tercero]++;
				if( tercero!=segundo)
				{
					int cuarto=padre[tercero];
					 if(cuarto!=tercero and mapa[cuarto]==0)
						hojas.push(cuarto);
				
				}
			}
			mapa[primer]++;
			con++;
		}
		
	}
	//cout<<" "<<con<<endl;
	cout<<con*cost<<endl;	

}