#include <bits/stdc++.h>
using namespace std;
#define max 10005
int nodos, aristas, a,b;
vector<int> mat[max];
vector<int> resive[max];
vector<int> manda[max];
vector<int> nods;
int vis[max];
int high[max];
int low[max];
int alt=1;
map <int, int> mapa;
void dfs(int nodo)
{
	//cout<<"\t"<<nodo<<endl;
	vis[nodo]=true;
	low[nodo]=high[nodo]=alt++;
	nods.push_back(nodo);	
	for(auto a: mat[nodo])
	{
		if(high[a]==-1)
			dfs(a);
		if(vis[a]==1)
			low[nodo]=min(low[a], low[nodo]);
	}
	if(low[nodo]==high[nodo])
	{
		//cout<<'\t'<<nodo<<": "<<low[nodo]<<endl;
		mapa[low[nodo]]=1;
		while(1)
		{
			int aux=nods.back();
			low[aux]=min(low[aux],low[nodo]);
			vis[aux]=-1;
			nods.pop_back();
			if(nodo==aux)
				break;
		}
	}

}
int main()
{
	scanf("%d %d",&nodos,&aristas);
	memset(high, -1, sizeof(high));
	memset(vis, -1,sizeof(vis));
	for(int i=0; i<aristas; i++)
	{
		scanf("%d %d",&a, &b);
		mat[a].push_back(b);
	}
	for(int i=1; i<=nodos; i++)
	{
		if(high[i]==-1)
			dfs(i);
	}
	
	for(int i=1; i<=nodos; i++)
	{
		//cout<<i<<": "<<low[i]<<endl;
		for(auto a: mat[i])
		{
			if(low[i]!=low[a])
			{
				manda[low[i]].push_back(low[a]);
				resive[low[a]].push_back(low[i]);

			}
		}
	}
	if(mapa.size()>1)
	{
		int raiz=0, hoja=0;
		for(int i=1; i<=nodos; i++)
		{
			if(mapa[i])
			{
				if(resive[i].size()==0)
					raiz++;
				if(manda[i].size()==0)
					hoja++;
			}
		}
		if(raiz>hoja)
			printf("%d\n",raiz);
		else
			printf("%d\n",hoja);
	}
	else
		printf("0\n");

}