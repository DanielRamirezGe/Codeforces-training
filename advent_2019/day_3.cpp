#include <bits/stdc++.h>
using namespace std;


int main()
{

	char dir,coma;
	int num;
	cin>>dir>>num;
	vector< pair<char,int> > uno,dos;
	uno.push_back({dir,num});
	while(cin>>coma and coma==',')
	{
		cin>>dir>>num;
		cout<<dir<<" "<<num<<endl;
		uno.push_back({dir,num});
	}
	dir=coma;
	cin>>num;
	dos.push_back({dir,num});
	cout<<endl<<endl;
	cout<<dir<<" "<<num<<endl;
	while(cin>>coma)
	{
		cin>>dir>>num;
		cout<<dir<<" "<<num<<endl;
		dos.push_back({dir,num});
	}
	map<pair<int,int> , int> mapa;
	int x=0,y=0;
	int con=1;
	for(auto var: uno)
	{
		if(var.first=='R')
		{
			for(int i=0; i<var.second; i++)
			{
				x++;
				mapa[{x,y}]=con;
				con++;
				
			}
			
		}
		if(var.first=='L')
		{
			for(int i=0; i<var.second; i++)
			{
				x--;
				mapa[{x,y}]=con;
				con++;
				
			}
		
		}
		if(var.first=='U')
		{
			for(int i=0; i<var.second; i++)
			{
				y++;
				mapa[{x,y}]=con;
				con++;
				
			}
			
		}
		if(var.first=='D')
		{
			for(int i=0; i<var.second; i++)
			{
				y--;
				mapa[{x,y}]=con;
				con++;
				
			}
		
		}
	}

	x=0;
	y=0;
	int menor=99999999;
	int suma;
	cout<<endl<<" el otro"<<endl;
	con=1;
	for(auto var: dos)
	{
		if(var.first=='R')
		{
			for(int i=0; i<var.second; i++)
			{

				x++;
				if(mapa[{x,y}])
				{
					suma=mapa[{x,y}]+con;
					if(suma<menor)
						menor=suma;
				}
				con++;
				
			}
		}
		if(var.first=='L')
		{
			for(int i=0; i<var.second; i++)
			{
				x--;
				if(mapa[{x,y}])
				{
					suma=mapa[{x,y}]+con;
					if(suma<menor)
						menor=suma;
				}
				con++;
				
			}
		}
		if(var.first=='U')
		{
			for(int i=0; i<var.second; i++)
			{
				y++;
				if(mapa[{x,y}])
				{
					suma=mapa[{x,y}]+con;
					if(suma<menor)
						menor=suma;
				}
				con++;
				
			}
		}
		if(var.first=='D')
		{
			for(int i=0; i<var.second; i++)
			{
				y--;
				if(mapa[{x,y}])
				{
					suma=mapa[{x,y}]+con;
					if(suma<menor)
						menor=suma;
				}
				con++;
			}
		}
	}
	cout<<menor<<endl;


}