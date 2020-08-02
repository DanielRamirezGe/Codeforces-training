#include <bits/stdc++.h>
using namespace std;
#define mx 1009
char mat[mx][mx];
int main()
{
	int n,a,b;
	pair<int,int> td[mx][mx];
	
	cin>>n;
	for(int i=0; i<mx; i++)
		for(int j=0; j<mx; j++)
			mat[i][j]='p';

	//cout<<"lkjalks"<<endl;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin>>a>>b;
			td[i][j]={a,b};
			if(a==i and j==b)
				mat[a][b]='X';

		}
	}
	bool no_es=false;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			int a=td[i][j].first;
			int b=td[i][j].second;
			if(a==-1 and b==-1 and mat[a][b]=='X')
				no_es=true;
			else
			{
				if(a!=-1 and b!=-1 )
				{
					mat[a][b]='X';
					if(a!=i and b!=j)
						no_es=true;

				}

			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			int a=td[i][j].first;
			int b=td[i][j].second;
			if(a==-1 and b==-1)
			{
				if(mat[i][j]=='p')
				{
					bool hay=true;
					for(int aux=i; aux<=n; aux++)
						if(mat[aux][j]=='X')
							hay=false;
					if(hay)
						mat[i][j]='D';
					hay=true;
					// for(int aux=i; aux>=1; aux--)
					// 	if(mat[aux][j]=='X')
					// 		hay=false;
					// if(hay)
					// 	mat[i][j]='U';
					hay=true;
					// for(int aux=j; aux>=1; aux--)
					// 	if(mat[i][aux]=='X')
					// 		hay=false;
					// if(hay)
					// 	mat[i][j]='L';
					
					hay=true;
					for(int aux=j; aux<=n; aux++)
						if(mat[i][aux]=='X')
							hay=false;
					if(hay)
						mat[i][j]='R';
					if(mat[i][j]=='p')
						no_es=true;

				}
			

			}
			else
			{
				if(mat[i][j]=='p')
				{
					if(a!=i and b!=j)
						no_es=true;
					else
					{
						if(a==i)
						{
							if(j>b)
								mat[i][j]='L';
							else
								mat[i][j]='R';
						}
						else
						{
							if(i>a)
								mat[i][j]='U';
							else
								mat[i][j]='D';
						}
					}
				}	
				else
					if(mat[i][j]=='X' and a!=i and j!=b)
						no_es=true;
			}
		}
	}
	if(no_es)
		cout<<"INVALID"<<endl;
	else
	{
		cout<<"VALID"<<endl;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
				cout<<mat[i][j];
			cout<<endl;
		}
	}



}