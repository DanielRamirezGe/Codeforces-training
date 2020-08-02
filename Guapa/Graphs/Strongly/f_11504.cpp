#include <bits/stdc++.h>
using namespace std;
#define max 100005
vector <int> mat[max];
bool viene[max];
bool visit[max];
bool exite[max];
int low[max];
int num[max];
vector <int> vec;
int paso=1;
int ban=0;
int vertex,edges;
int cases,a,b;
void imprimir()
{
	for(int i=1; i<=vertex; i++)
		cout<<" i: "<<i<<" low: "<<low[i]<<"   num: "<<num[i]<<endl;
}
void dfs_nuevo(int nodo)
{
	visit[nodo]=true;
	exite[low[nodo]]=true;
	for(auto a: mat[nodo])
	{
		if(low[nodo]!=low[a])
			viene[low[a]]=true;
		if(!visit[a])
			dfs_nuevo(a);
	}
}
void dfs(int nodo)
{
	vec.push_back(nodo);
	visit[nodo]=true;
	low[nodo]=num[nodo]=paso++;
	for(auto a: mat[nodo])
	{
		if(num[a]==false)
			dfs(a);
		if(visit[a])
			low[nodo]=min(low[a],low[nodo]);
	}
	if(low[nodo]==num[nodo])
	{
		while(1)
		{

			int s=vec.back();
			low[s]=min(low[nodo],low[s]);
			visit[s]=false;
			vec.pop_back();
			if(s==nodo)
				break;
		}
	}
}
int main()
{

	cin>>cases;
	
	for(int i=0; i<cases; i++)
	{
		paso=1;
		for(int i=0; i<max; i++)
			mat[i].clear();
		
		cin>>vertex>>edges;
		memset(viene, 0, sizeof(viene));
		memset (visit,0,sizeof(visit));
		memset(low,0,sizeof(low));
		memset(num,0,sizeof(num));
		memset(exite,0,sizeof(exite));
		for(int j=0; j<edges; j++)
		{
			cin>>a>>b;
			mat[a].push_back(b);
		}
		int con=0;
		for(int i=1; i<=vertex; i++)
			if(num[i]==false)
				dfs(i);
		memset(visit,0,sizeof(visit));
		for(int i=1; i<=vertex; i++)
			if(!visit[i])
				dfs_nuevo(i);
		for(int i=1; i<=vertex; i++)
			if(exite[i] and !viene[i])
				con++;
		//imprimir();	

		cout<<con<<endl;
	}
}