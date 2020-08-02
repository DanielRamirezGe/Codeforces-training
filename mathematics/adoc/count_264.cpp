#include <bits/stdc++.h>
using namespace std;
#define maxi 10000009
int main()
{
	vector<int> arriba;
	vector <int> abajo;
	int con=2;
	arriba.push_back(1);
	abajo.push_back(1);
	while(arriba.size()<maxi)
	{
		if(con%2==0)
		{
			for(int i=1; i<=con and arriba.size()<maxi; i++)
				arriba.push_back(i);
		}
		else
		{
			for(int i=con; i>=1 and arriba.size()<maxi; i--)
				arriba.push_back(i);
		}
		
		con++;
	}
	con=2;
	while(abajo.size()<maxi)
	{
		if(con%2==1)
		{
			for(int i=1; i<=con and abajo.size()<maxi; i++)
				abajo.push_back(i); 	
		}
		else
		{
			for(int i=con; i>=1 and abajo.size()<maxi; i--)
				abajo.push_back(i);
				
		}
			
		con++;
	}
	/*for(int i=0; i<15; i++)
		cout<<arriba[i]<<"/"<<abajo[i]<<"  ";
	cout<<endl;*/
	int num,aux;
	while(cin>>aux)
	{
		cout<<"TERM "<<aux<<" IS "<<arriba[aux-1]<<"/"<<abajo[aux-1]<<endl;
	}


}