#include <bits/stdc++.h>
using namespace std;
#define maxi 2000
#define inf 99999999
int a,b;
vector< pair<int,int>> uno;
vector< pair<int,int>> dos;
pair<int,int> mat[maxi][maxi];
int busca;
pair<int,int> maximo (pair<int,int> a, pair<int,int> b)
{
	if(a.first > b.first)
		return a;
	if(b.first > a.first)
		return b;
	if(a.second < b.second )
		return a;
	return b;
}
pair<int,int> f(int i, int j)
{
	if(i>=a)
		return {0,0};
	if(j>=b)
		return {0,0};
	if(mat[i][j].first!=-1)
		return mat[i][j];
	pair<int,int> a={0,0};
	pair<int,int> b={0,0};
	pair<int,int> c={0,0};
	
	if(uno[i].first==dos[j].first)
	{
		pair<int,int> auxi=f(i+1,j+1);
		a.first = uno[i].second+dos[j].second + auxi.first;
		a.second=auxi.second+1;
	}
	b=f(i+1,j);
	c=f(i,j+1);
	return mat[i][j]=maximo( maximo(a,b), c);
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
		for(int j=0; j<b; j++)
		{
			cin>>cad>>cad>>aux;
			if(mapa[cad]==0)
			{
				mapa[cad]=mapa.size()+1;
			}
			dos.push_back({mapa[cad],aux});
		}
		memset(mat, -1, sizeof(mat));
		pair<int,int> ms=f(0,0);
		cout<<ms.first<<" "<<ms.second<<endl;


	}
}