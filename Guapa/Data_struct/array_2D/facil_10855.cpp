#include <bits/stdc++.h>
using namespace std;
#define max
int main()
{
	int n,m;
	while(scanf("%d %d",&m,&n)==2 and m!=0 and n!=0)
	{
		char mat[m][m], uno[n][n], dos[n][n], tres[n][n], cuatro[n][n];
		for(int i=0; i<m; i++)
			for(int j=0; j<m; j++)
				cin>>mat[i][j];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin>>uno[i][j];

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				dos[j][n-1-i]=uno[i][j];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				tres[j][n-1-i]=dos[i][j];

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cuatro[j][n-1-i]=tres[i][j];

/*		for(int h=0; h<n; h++, cout<<endl)
				for(int k=0; k<n; k++)
					cout<<uno[h][k];

		for(int h=0; h<n; h++, cout<<endl)
				for(int k=0; k<n; k++)
					cout<<dos[h][k];


		for(int h=0; h<n; h++, cout<<endl)
				for(int k=0; k<n; k++)
					cout<<tres[h][k];

		for(int h=0; h<n; h++, cout<<endl)
				for(int k=0; k<n; k++)
					cout<<cuatro[h][k];*/

		int con_uno=0, con_dos=0, con_tres=0, con_cuatro=0;
		for(int i=0; i+n-1< m; i++)
			for(int j=0; j+n-1<m; j++)
			{
				bool b_uno=0, b_dos=0, b_tres=0, b_cuatro=0;
				for(int h=0; h<n; h++)
					for(int k=0; k<n; k++)
					{
						if(uno[h][k]!=mat[i+h][j+k])
							b_uno=1;
						if(dos[h][k]!=mat[i+h][j+k])
							b_dos=1;
						if(tres[h][k]!=mat[i+h][j+k])
							b_tres=1;
						if(cuatro[h][k]!=mat[i+h][j+k])
							b_cuatro=1;
					}
				if(!b_uno)
					con_uno++;
				if(!b_dos)
					con_dos++;
				if(!b_tres)
					con_tres++;
				if(!b_cuatro)
				{
					con_cuatro++;
				}
			}
		cout<<con_uno<<" "<<con_dos<<" "<<con_tres<<" "<<con_cuatro<<endl;
	}
}