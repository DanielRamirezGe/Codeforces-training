#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	bool res[a][b];
	memset(res, 0, sizeof(res));
	int mat[a][b];
	for(int i=0; i<a; i++)
		for(int j=0; j<b; j++)
			cin>>mat[i][j];
		
	for(int i=1; i<a-1; i++)
		for(int j=1; j<b-1; j++)
			if(mat[i-1][j]>mat[i][j])
				if(mat[i+1][j]>mat[i][j])
					if(mat[i][j+1]>mat[i][j])
						if(mat[i][j-1]>mat[i][j])
							res[i][j]=1;
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<b; j++)
		{
			cout<<res[i][j];
			if(j!=b-1)
				cout<<" ";
			else
				cout<<endl;
		}
	}
}