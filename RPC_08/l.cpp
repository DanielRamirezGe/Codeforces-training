#include <bits/stdc++.h>
using namespace std;
int main()
{
	int dias, aux;
	cin>>dias;
	map<int,int> mapa;
	for(int i=0; i<dias; i++)
	{
		cin>>aux;
		mapa[aux]++;
	}
	int acumulada=0;
	int busg=0;
	int res=0;
	for(int i=1; i<=365; i++)
	{
		
		if(acumulada!=0 or busg)
		{
			acumulada+=busg;
			if(acumulada>=20)
			{
				acumulada=0;
				busg=0;
				res++;
				
			}
			if(mapa[i])
				busg++;
			
			
		}
		else
			if(mapa[i])
			{
				busg++;
			}
			//cout<<i<<" "<<busg<<" "<<acumulada<<endl;
	}
	if(acumulada>0 or busg )
		res++;
	cout<<res<<endl;
}