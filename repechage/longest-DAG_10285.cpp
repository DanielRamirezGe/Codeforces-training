#include <bits/stdc++.h>
using namespace std;
#define maxi 109
#define inf 999999
int mat[maxi][maxi];
int dis[maxi][maxi];
typedef pair<int,int> ii;
int fun(int a, int b )
{
	if(dis[a][b]!=-1)
		return dis[a][b];

	int suma=0,aux=0;
	if(mat[a+1][b]>mat[a][b])
	{
		aux=fun(a+1,b);
		aux++;
	}
	suma=max(suma,aux);
	if(mat[a-1][b]>mat[a][b])
	{
		aux=fun(a-1, b);
		aux++;
	}
	suma=max(suma,aux);
	if(mat[a][b+1]>mat[a][b])
	{
		aux=fun(a, b+1);
		aux++;
	}
	suma=max(suma,aux);
	if(mat[a][b-1]>mat[a][b])
	{
		aux=fun(a,b-1);
		aux++;
	}
	suma=max(suma,aux);
	return dis[a][b]=suma;
}
int main()
{
	int cases,a,b;
	string nom;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>nom>>a>>b;
		for(int i=0; i<maxi; i++)
			for(int j=0; j<maxi; j++)
				mat[i][j]=-inf;
		memset(dis, -1, sizeof(dis));
		for(int i=1; i<=a; i++)
			for(int j=1; j<=b; j++)
				cin>>mat[i][j];
			
		int m=0;	
		for(int i=1; i<=a; i++)
			for(int j=1; j<=b; j++)
			{
				int aux=fun(i,j);
				m=max(m,aux);	
			}
		cout<<nom<<": "<<m+1<<endl;
		

	}
}