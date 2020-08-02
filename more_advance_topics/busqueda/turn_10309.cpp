#include <bits/stdc++.h>
using namespace std;
#define maxi 10 	
#define inf 999999
bool mat[maxi][maxi];
void cam(int i, int j)
{
	if(mat[i][j])
		mat[i][j]=0;
	else
		mat[i][j]=1;
	if(i>0)
		if(mat[i-1][j])
			mat[i-1][j]=0;
		else
			mat[i-1][j]=1;
	if(i<maxi-1)
		if(mat[i+1][j])
			mat[i+1][j]=0;
		else
			mat[i+1][j]=1;

	if(j>0)
		if(mat[i][j-1])
			mat[i][j-1]=0;
		else
			mat[i][j-1]=1;
	if(j<maxi-1)
		if(mat[i][j+1])
			mat[i][j+1]=0;
		else
			mat[i][j+1]=1;


}
int f(int con, int vis[maxi][maxi])
{
	for(int i=0; i<maxi; i++,cout<<endl)
		for(int j=0; j<maxi; j++)
			if(mat[i][j]==0)
				cout<<'#';
			else
				cout<<'0';
		cout<<endl;
	bool ban=1;
	for(int i=0; i<maxi and ban; i++)
		for(int j=0; j<maxi and ban; j++)
			if(mat[i][j])
				ban=0;
	if(ban)
		return con;

	if(con>100)
		return inf;

	int min=inf,aux;
	for(int i=0; i<maxi; i++)
	{
		for(int j=0; j<maxi; j++)
		{
			if(mat[i][j] and !vis[i][j])
			{
				cam(i,j);
				vis[i][j]=1;
				aux=f(con+1, vis);
				cam(i,j);
				if(aux<min)
					min=aux;
				vis[i][j]=0;
				

			}
		}
	}
	return min;
}
int main()
{
	string cad;
	char c;
	int vis[maxi][maxi];
	while(cin>>cad and cad!="end")
	{
		for(int i=0; i<maxi; i++)
			for(int j=0; j<maxi; j++)
			{
				cin>>c;
				if(c=='#')
					mat[i][j]=0;
				else
					mat[i][j]=1;	
			}
		memset(vis, 0, sizeof(vis));
		cout<<f(0,vis)<<endl;
	}
}