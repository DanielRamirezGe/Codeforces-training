#include <bits/stdc++.h>
using namespace std;
#define maxi 3009
#define mit 1505
#define inf 9999999
int auxo[maxi][maxi];
typedef struct m
{
	int mat[maxi][maxi];
}m;
m matriz;
vector<pair<int,int>> vec;
int ban;
int s=0, t=maxi-1;
int visi[maxi];


void dfs( int nodo)
{
	visi[nodo]=1;
	if(nodo==t)
	{
		ban=1;
		return;
	}
	for(int i=0; i<maxi; i++)
		if(matriz.mat[nodo][i]>0 and !visi[i])
		{
			vec.push_back({nodo,i});
			dfs(i);
			if(ban)
				return;
			vec.pop_back();
		}
}
void dfs_dos( int nodo,int mat[maxi][maxi])
{
	visi[nodo]=1;
	if(nodo==t)
	{
		ban=1;
		return;
	}
	for(int i=0; i<maxi; i++)
		if(mat[nodo][i]>0 and !visi[i])
		{
			vec.push_back({nodo,i});
			dfs_dos(i,mat);
			if(ban)
				return;
			vec.pop_back();
		}
}
int max_flow()
{

	int max_f=0;
	while(1)
	{
		vec.clear();
		memset(visi, 0, sizeof(visi));
		ban=0;
		dfs(s);
		if(!ban)
			break;
		
		for(auto a: vec)
		{
			matriz.mat[a.first][a.second]-=1;
			matriz.mat[a.second][a.first]+=1;
		}
		max_f+=1;
	}
	return max_f;
}
int m_dos(m ma)
{
	cout<<"ini"<<endl;

	for(int i=0; i<10; i++,cout<<endl)
			for(int j=0; j<10; j++)
				printf("%p ",&ma.mat[i][j]);
			cout<<endl;
	for(int i=0; i<10; i++,cout<<endl)
			for(int j=0; j<10; j++)
				printf("%p ",&matriz.mat[i][j]);
	cout<<endl;

	cout<<"fine"<<endl;
	int max_f=0;
	while(1)
	{
		vec.clear();
		memset(visi, 0, sizeof(visi));
		ban=0;
		dfs_dos(s, ma.mat);
		if(!ban)
			break;
		
		for(auto a: vec)
		{
			ma.mat[a.first][a.second]-=1;
			ma.mat[a.second][a.first]+=1;
		}
		max_f+=1;
	}
	return max_f;
}
int main()
{
	int n,p,k,a,b;
	cin>>n>>p>>k;
	
	memset(matriz.mat, 0, sizeof(matriz.mat));
	memset(auxo, 0, sizeof(auxo));
	
	
	for(int i=0; i<k; i++)
	{
		cin>>a>>b;
		matriz.mat[s][a]=1;
		b+=mit;
		matriz.mat[a][b]++;
		matriz.mat[b][t]=1;
	}
	
	
	int max_f= max_flow();
	int plos=0;

	
	
	for(int i=1; i<=n; i++)
	{
		
		
		matriz.mat[s][i]+=2;
		
		int p=m_dos(matriz);
		matriz.mat[s][i]-=2;
		if(plos<p)
			plos=p;
		
		

	}
	cout<<max_f+plos<<endl;

}