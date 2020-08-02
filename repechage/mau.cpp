#include <bits/stdc++.h>
using namespace std;
#define maxi 1009
#define inf 99999999
typedef pair<long long,long long> ii;
vector<ii> mat[maxi];
vector <int> rutas[maxi]; 
long long nodos, aristas;
long long dis_uno[maxi];
long long dis_dos[maxi];
long long res[maxi];
long long mini;
long long dp(int nodo)
{
	if(nodo==2)
		return 1;
	if(res[nodo]!=-1)
		return res[nodo];
	long long suma=0;
	for(auto x: rutas[nodo])
		suma+=dp(x);
	return suma;
}

int main()
{
	long long a,b,p;
	cin>>nodos;
	while(nodos!=0)
	{
		memset(res, -1, sizeof(res));
		cin>>aristas;
		for(long long i=0; i<maxi; i++)
		{
			mat[i].clear();
			dis_dos[i]=inf;
			dis_uno[i]=inf;
			rutas[i].clear();
		}
	
		for(long long i=0; i<aristas; i++)
		{
			cin>>a>>b>>p;
			mat[a].push_back({b,p});
			mat[b].push_back({a,p});
		} 	

		priority_queue < ii, vector<ii>, greater<ii> > pq;
		pq.push({0,1});
		dis_uno[1]=0;
		while(!pq.empty())
		{
			auto u=pq.top();
			long long d=u.first;
			long long n=u.second;
			pq.pop();
			if(d>dis_uno[n])
				continue;
			for(auto x: mat[n])
			{
				if(dis_uno[n]+ x.second < dis_uno[x.first])
				{
					dis_uno[	x.first]=dis_uno[n]+ x.second;
					pq.push({dis_uno[x.first], x.first});
				}
			}
		}
		dis_dos[2]=0;
		pq.push({0,2});
		while(!pq.empty())
		{
			auto u=pq.top();
			long long d=u.first;
			long long n=u.second;
			pq.pop();
			if(d>dis_dos[n])
				continue;
			for(auto x: mat[n])
			{
				if(dis_dos[n]+ x.second < dis_dos[x.first])
				{
					dis_dos[x.first]=dis_dos[n]+ x.second;
					pq.push({dis_dos[x.first], x.first});
				}
			}
		}
		mini=dis_uno[2];
		for(int i=1; i<=nodos; i++)
		{
			for(auto x: mat[i])
			{
				if(dis_uno[i]+x.second+dis_dos[x.first]==mini)
				{
					//cout<<i<<" : "<<x.first<<endl;
					rutas[i].push_back(x.first);
				}
				
			}
		}
		
		cout<<dp(1)<<endl;


		cin>>nodos;
	} 	
}