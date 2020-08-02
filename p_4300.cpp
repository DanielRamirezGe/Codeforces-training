#include <bits/stdc++.h>
using namespace std;
/*#define maxi 14
bool mat[maxi][maxi];
long long res[maxi][maxi][maxi];
long long f(int n, int i, int j)
{

	if(n==0)
		return 1;
	if(res[i][j][n]!=-1)
		return res[i][j][n];
	long long suma=0;
	if(i>0)
	{
		if(j>0)
			if(!mat[i-1][j-1])
			{
				mat[i-1][j-1]=1;
				suma+=f(n-1, i-1, j-1);
				mat[i-1][j-1]=0;
			}
		if(!mat[i-1][j])
		{
			mat[i-1][j]=1;
			suma+=f(n-1, i-1, j);
			mat[i-1][j]=0;
		}
		if(!mat[i-1][j+1])
		{
			mat[i-1][j+1]=1;
			suma+=f(n-1, i-1, j+1);
			mat[i-1][j+1]=0;
		}
		
	}
	if(j>0)
	{
		if(!mat[i+1][j-1])
		{
			mat[i+1][j-1]=1;
			suma+=f(n-1, i+1, j-1);
			mat[i+1][j-1]=0;
		}
		if(!mat[i][j-1])
		{
			mat[i][j-1]=1;
			suma+=f(n-1, i, j-1);
			mat[i][j-1]=0;
		}
		
	}
	if(!mat[i][j+1])
	{
		mat[i][j+1]=1;
		suma+=f(n-1, i, j+1);
		mat[i][j+1]=0;
	}
	if(!mat[i+1][j+1])
	{
		mat[i+1][j+1]=1;
		suma+=f(n-1, i+1, j+1);
		mat[i+1][j+1]=0;
	}
	if(!mat[i+1][j])
	{
		mat[i+1][j]=1;
		suma+=f(n-1, i+1, j);
		mat[i+1][j]=0;
	}
	return res[i][j][n]=suma;


}*/
int main()
{
	/*int cases,n;
	scanf("%d",&cases);
	
	for(int i=0; i<cases; i++)
	{
		memset(res,-1,sizeof(res));
		memset(mat,0,sizeof(mat));
		scanf("%d",&n);
		mat[0][0]=1;
		printf("%lld\n",f(n,0,0));
	}*/
	int cases,n;
	long long arr[]={3,15,75,391,2065,11091,60215,330003,1820869,10103153,56313047,315071801, 1768489771,9953853677};
	scanf("%d",&cases);
	
	for(int i=0; i<cases; i++)
	{
		scanf("%d",&n);
		printf("%lld\n",arr[n-1]);
	}
}