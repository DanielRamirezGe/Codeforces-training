#include <bits/stdc++.h>
using namespace std;
#define max_nodo 10001
#define tama 800001
typedef pair<int, map<int,int>> pm;
pair<int, map<int, int> > segment[tama];
int primera[max_nodo];
int level[max_nodo];
vector<int> eulerian;
vector<int> mat[max_nodo];
bool visitado[max_nodo];
int N, Q,a,b;
pm nada;
void build(int i, int j, int p)
{
	if(i==j)
	{
		segment[p].first=eulerian[i];
		segment[p].second[eulerian[i]]++;
		return;
	}	
	build(i, (i+j)/2, p<<1);
	build(((i+j)/2)+1, j, (p<<1)+1);
	int left=level[segment[p<<1].first];
	int right=level[segment[(p<<1)+1].first];

	for(auto a: segment[p<<1].second)
			segment[p].second[a.first]=1;

	for(auto a: segment[(p<<1)+1].second)
			segment[p].second[a.first]=1;		
	if(left<right)
	{
		

		segment[p].first=segment[p<<1].first;
	}
	else
	{
		
		segment[p].first=segment[(p<<1)+1].first;
	}
	
	


}
pm query(int i, int j, int a, int b, int p)
{
	if(i>b or j<a)
		return nada;
	if(i>=a and j<=b)
		return segment[p];	
	
	pm left=query(i, (i+j)/2, a, b, p<<1);
	pm rigth= query(((i+j)/2)+1, j, a, b, (p<<1)+1);
	if(left.first==-1)
		return rigth;
	if(rigth.first==-1)
		return left;
	pm res;

	int l=level[left.first];
	int r=level[rigth.first];
	if(l<r)
	{
		for(auto a: left.second)
			res.second[a.first]=1;
		
		res.first=left.first;
		return res;
	}
	else
	{
		for(auto a: rigth.second)
			res.second[a.first]=1;
		
		res.first=rigth.first;
		return res;
	}
}
void dfs(int nodo, int prof)
{
	nada.first=-1;
	visitado[nodo]=true;
	level[nodo]=prof;
	primera[nodo]=eulerian.size();
	eulerian.push_back(nodo);
	for(int i=0; i<mat[nodo].size(); i++)
	{
		int a=mat[nodo][i];
		if(!visitado[a])
		{
			dfs(a, prof+1);
			eulerian.push_back(nodo);
		}
	}

}
int main()
{
	scanf("%d %d",&N,&Q);
	for(int i=1; i<N; i++)
	{
		scanf("%d %d",&a,&b);
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	memset(visitado, 0, sizeof(visitado));

	dfs(1, 0);
	build(0, eulerian.size(), 1);

	int a,b,c,d;
	for(int i=0; i<Q; i++)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		int uno, dos;
		uno=primera[a];
		dos=primera[b];
		if(uno>dos)
		{
			int tres=uno;
			uno=dos;
			dos=tres;
		}
		pm primero=query(0,eulerian.size(), uno, dos, 1 );

		uno=primera[c];
		dos=primera[d];
		if(uno>dos)
		{
			int tres=uno;
			uno=dos;
			dos=tres;
		}
		pm segundo=query(0,eulerian.size(), uno, dos, 1 );
		int con=0;
		for(auto au: primero.second)
		{
			cout<<au.first<<endl;
			if(segundo.second[au.first])
				con++;
		}
		cout<<con<<endl;
		cout<<endl;		
	}
	return 0;

}