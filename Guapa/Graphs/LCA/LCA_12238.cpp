#include <bits/stdc++.h>
using namespace std;
#define max 1000005
vector<pair<int,long long>> mat[max];
bool vis[max];
int high[max];
long long fist[max];
long long distancia[max];
vector<long long> euler;
int segment[max*4];
void dfs(long long nodo, long long h)
{
	vis[nodo]=true;
	fist[nodo]=euler.size();
	high[nodo]=h;
	euler.push_back(nodo);
	for(int i=0; i<mat[nodo].size(); i++)
	{

		int u=mat[nodo][i].first;
		int d=mat[nodo][i].second;
		if(!vis[u])
		{
			distancia[u]=distancia[nodo]+d;
			//cout<<distancia[u]<<" "<<u<<" "<<h+1<<" "<<euler.size()<<endl;
			dfs(u, h+1);
			euler.push_back(nodo);
		}
	}
}
void build(int i, int j, int p)
{
	if(i==j)
	{
		segment[p]=euler[i];
		return;
	}
	build(i, (i+j)/2, p<<1);
	build(((i+j)/2)+1, j, (p<<1)+1);
	int l=segment[p<<1];
	int r=segment[(p<<1)+1];
	segment[p]=(high[l]<high[r])? l:r;
}
int consulta(int i, int j, int a, int b, int p)
{
	if(i>b or j<a)
		return -1;
	if(i>=a and j<=b)
		return segment[p];
	int l= consulta(i, (i+j)/2, a, b, p<<1);
	int r=consulta(((i+j)/2)+1, j, a, b, (p<<1)+1);
	if(l==-1)
		return r;
	if(r==-1)
		return l;
	return(high[l]<high[r])? l: r;
}
int main()
{
	long long nodos, dis, query, a,b;
	while(cin>>nodos and nodos!=0)
	{
		euler.clear();
		memset(vis,0,sizeof(vis));
		for(long long i=0; i<max; i++)
			mat[i].clear();
		for(long long i=1; i<nodos; i++)
		{
			cin>>a>>dis;
			mat[i].push_back({a,dis});
			mat[a].push_back({i,dis});
		}
		cin>>query;
		distancia[0]=0;
		dfs(0,1);
		build(0, euler.size(), 1);
		for(int i=0; i<query; i++)
		{
			cin>>a>>b;
			int m=fist[a];
			int n=fist[b];
			if(m>n)
			{
				int c=m;
				m=n;
				n=c;
			}
			//cout<<m<<" "<<n<<endl;
			int lca=consulta(0, euler.size(), m, n, 1);

			cout<<distancia[a]+distancia[b]-(2*distancia[lca]);
			if(i!=query-1)
				cout<<" ";
		}
		cout<<endl;	
	}
}