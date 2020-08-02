#include <bits/stdc++.h>
using namespace std;
#define maxi 200
char mat[maxi][maxi];
void llenar()
{
	for(int i=0; i<maxi; i++)
		for(int j=0; j<maxi; j++)
			mat[i][j]=' ';

	for(int i=0; i<maxi; i++)	
		mat[i][0]='|';

	for(int i=0; i<maxi; i++)
		mat[maxi-1][i]='-';
	mat[maxi-1][0]='+';
}
int main()
{
	string cad;
	int num;
	cin>>num;
	
	for(int i=0; i<num; i++)
	{
		cin>>cad;
		int maximo=100;
		int minimo=100;
		llenar();
		int ant=0;
		int con=100;
		int ultimo[maxi];
		memset(ultimo, 0, sizeof(ultimo));
		for(int i=2; i<=cad.size()+2; i++)
		{

			if(cad[i-2]=='R')
			{
				ant=1;
				mat[con][i]='/';
				ultimo[con]=i;
				//cout<<i<<" "<<con<<" "<<mat[i][con]<<endl;
				con--;
			}
			if(cad[i-2]=='C')
			{
				ant=2;
				mat[con][i]='_';
				ultimo[con]=i+1;
			}
			if(cad[i-2]=='F')
			{
				con++;
				mat[con][i]=92;
				ultimo[con]=i+1;
				 		
			}
			if(minimo>con)
				minimo=con;
			if(maximo<con)
				maximo=con;
			
		}
		cout<<"Case #"<<i+1<<":"<<endl;
		for(int i=minimo+1; i<=maximo; i++)
		{
			
			for(int j=0; j<=cad.size() and j<ultimo[i]; j++)
				printf("%c",mat[i][j]);
			cout<<endl;
		}
		cout<<"+";
		for(int i=0; i<=cad.size(); ++i)
			cout<<'-';
		cout<<endl;
		if(i!=num-1)
			cout<<endl;

	}
}