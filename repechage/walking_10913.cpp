#include <bits/stdc++.h>
using namespace std;
#define maxi 100
#define inf 99999

int n,k;
int mat[maxi][maxi];
int res[maxi][maxi][3][6];

int dp(int a,int b, int est, int con)
{
	
	if(a==0 or a==n+1 or b==0 or b==n+1)
		return -inf;
	if(con>k)
		return -inf;
	if(a==n and b==n)
	{
		int dos=con;
		if(mat[a][b]<0)
			dos=con+1;
		if(dos>k)
			return -inf;
		return mat[a][b];
	}
	if(res[a][b][est][con]!=-1)
		return res[a][b][est][con];
	int suma=-inf, aux=-inf;
	if(est==0)
	{
		int dos=con;
		if(mat[a][b]<0)
			dos=con+1;
		aux=dp(a+1, b, 2, dos);
		suma=max(aux, suma);
		aux=dp(a, b+1, 0, dos);
		suma=max(aux, suma);
	}
	if(est==1)
	{
		int dos=con;
		if(mat[a][b]<0)
			dos=con+1;

		aux=dp(a+1, b, 2, dos);
		suma=max(aux, suma);
		aux=dp(a, b-1, 1, dos);
		suma=max(aux, suma);
		
	}
	if(est==2)
	{
		int dos=con;
		if(mat[a][b]<0)
			dos=con+1;
		aux=dp(a+1, b, 2, dos);
		suma=max(aux, suma);
		aux=dp(a, b+1, 0, dos);
		suma=max(aux, suma);
		aux=dp(a, b-1, 1, dos);
		suma=max(aux, suma);
		
		
		
	}
	
	if(suma==-inf)
		return res[a][b][est][con]=-inf;
	return res[a][b][est][con]=suma+mat[a][b];

}
int main()
{	
	int con=1;
	while(cin>>n>>k and (n!=0 or k!=0) )
	{
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				cin>>mat[i][j];
		memset(res, -1, sizeof(res));
		int num=dp(1,1,0,0);
		if(num==-inf)
			cout<<"Case "<<con<<": impossible"<<endl;
		else
			cout<<"Case "<<con<<": "<<num<<endl;
		con++;

	}
}