#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	cin>>cad;
	
	
	int j=1;

	int m=99999999;
	int a,b;

	for(int i=0; i<cad.size(); i++)
	{

		int dif [cad.size()];
		memset(dif, 0, sizeof(dif));
		int mat [4][cad.size()];
		memset( mat, 0, sizeof(mat) );

		for(int p =i; p<cad.size(); p++)
		{
			//cout<<cad[p]<<endl
			for(int h=0; p!=0 and  h<4; h++)
				mat[h][p]=mat[h][p-1];

			switch(cad[p]){
				case 'R':
					mat[0][p]++;
					break;
				case 'G':
					mat[1][p]++;
					break;
				case 'B':
					mat[2][p]++;
					break;
				case 'Y':
					mat[3][p]++;
					break;
					
			}

			dif[p] = max( max(mat[0][p],mat[1][p] ) , max(mat[2][p],mat[3][p] ) ) - min( min(mat[0][p],mat[1][p] ) , min(mat[2][p],mat[3][p] ) ) ;

			if( m > dif[p] or (m==dif[p] and abs(i-p)> abs(a-b)))
			{
				m= dif[p];
				a=i;
				b=p;
			}
			
		}
	}
	cout<<m<<" "<<abs(a-b)+1<<endl;
	cout<<a+1<<" "<<b+1<<endl;

	

}