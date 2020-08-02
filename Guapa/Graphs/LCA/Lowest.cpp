#include <bits/stdc++.h>
using namespace std;
#define max 10000
#define inf 9999999
vector <int> mat[max];
int segment[max*8];
vector<int> euler_tur;
int hig[max];
int fisrt[max];
bool vis[max];
int h=0;
void dfs(int nodo,int h )
{
	vis[nodo]=true;
	fisrt[nodo]=euler_tur.size(),
	hig[nodo]=h;
	euler_tur.push_back(nodo);
	for(auto a: mat[nodo])
	{
		if(!vis[a])
		{
			dfs(a, h+1);
			euler_tur.push_back(nodo);
		}
	}

}
void build(int i, int j, int p)
{
	if(i==j)
	{
		segment[p]=euler_tur[i];
		return;
	}
	build(i, (i+j)/2, p<<1);
	build(((i+j)/2)+1, j, (p<<1)+1);
	int l=segment[p<<1];
	int r=segment[(p<<1)+1];
	segment[p]=(hig[l]< hig[r]) ? l : r;
}
int query(int i, int j, int a, int b, int p)
{
	if(i>b or j<a)
		return inf;
	if(i>=a and j<=b)
	{
		return segment[p];
	}
	int l=query(i, (i+j)/2, a, b, p<<1);
	int r=query(((i+j)/2)+1, j, a, b, (p<<1)+1);
	if(l==inf)
		return r;
	if (r==inf)
		return l;
	return (hig[l]<hig[r]? l: r);
}
int main()
{
	memset(vis,0, sizeof(vis));
	memset(segment,0, sizeof(segment));
	int a,b,n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a>>b;
		mat[a].push_back(b);
	}
	dfs(1,1);
	build(0, euler_tur.size(), 1);
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a>>b;
		int m=fisrt[a];
		int n=fisrt[b];
		if(m>n)
		{
			int c=m;
			m=n;
			n=c;
		}
		cout<<query(0, euler_tur.size(), m, n, 1)<<endl;
	}

	
}