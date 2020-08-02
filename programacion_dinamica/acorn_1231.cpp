#include <bits/stdc++.h>
using namespace std;
#define maxi 2009
int res[maxi][maxi];
int arboles, salto, altura;
int mat[maxi][maxi]; 
int max_alt[maxi];
int main()
{
	int cases,p,n;
	cin>>cases;
	for (int i=0; i<cases; i++)
	{
		memset(mat, 0, sizeof(mat));
		cin>>arboles>>altura>>salto;
		for(int j=0; j<arboles; j++)
		{
			cin>>n;
			for(int h=0; h<n; h++)
			{
				cin>>p;
				mat[j][p]++;
			}
		}
		memset(max_alt, 0 , sizeof(max_alt));
		for(int i=0; i<=altura; i++)
		{	
			int pi=0;
			int baja=i-salto;
			for(int j=0; j<arboles; j++)
			{
				int a=0, b=0;
				if(baja>=0)n
					a=max_alt[baja];
				if(i>0)
					b=res[j][i-1];
				res[j][i]=mat[j][i]+max(a,b);
				if(res[j][i]>pi)
					pi=res[j][i];
			}
			max_alt[i]=pi;
		}
		cout<<max_alt[altura]<<endl;
	}
	


}