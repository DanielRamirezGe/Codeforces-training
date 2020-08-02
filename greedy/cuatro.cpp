#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	char mat[a][b];
	for(int i=0; i<a; i++)
		for(int j=0; j<b; j++)
			cin>>mat[i][j];
	if(a>=2 and b>=2)
	{
		int con=0;
		if(mat[0][1]!='#')
			con++;
		if(mat[1][0]!='#')
			con++;
		cout<<con<<endl;
	}
	else
	{
		if(a>=2)
		{
			int con=0;
			if(mat[1][0]!='#')
				con++;
			cout<<con<<endl;
		}
		else
		{
			int con=0;
			if(mat[0][1]!='#')
				con++;
			cout<<con<<endl;
		}
	}
}