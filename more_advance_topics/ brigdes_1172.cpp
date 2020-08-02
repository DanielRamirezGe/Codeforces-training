#include <bits/stdc++.h>
using namespace std;
#define maxi 2000
int a,b;
vector< pair<int,int>> uno;
vector< pair<int,int>> dos;
int mat[maxi][maxi];
int f(int i, int j)
{
	if(i>=a)
		return 0;
	if(j>=b)
		return 0;
	if(mat[i][j]!=-1)
		return mat[i][j];
	int a=0;
	int b=0;
	int c=0;
	if(uno[i].first==dos[j].first)
		a=uno[i].second+dos[j].second;
	b=f(i+1,j);
	c=f(i,j+1);
	return mat[i][j]=max(max(a,b),c);
}
int main()
{
	int cases;
	cin>>cases;
	string cad;
	int aux;
	map <string, int> mapa;
	for(int i=0; i<cases; i++)
	{
		uno.clear();
		dos.clear();
		mapa.clear();
		cin>>a;
		for(int j=0; j<a; j++)
		{
			cin>>cad>>cad>>aux;
			if(mapa[cad]==0)
			{
				mapa[cad]=mapa.size()+1;
			}
			uno.push_back({mapa[cad],aux});
		}
		cin>>b;
		for(int j=0; j<a; j++)
		{
			cin>>cad>>cad>>aux;
			if(mapa[cad]==0)
			{
				mapa[cad]=mapa.size()+1;
			}
			dos.push_back({mapa[cad],aux});
		}
		memset(mat, -1, sizeof(mat));
		cout<<f(0,0)<<endl;


	}
}