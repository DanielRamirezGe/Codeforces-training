#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num,aux;
	cin>>num;
	map<int,int> mapa;
	for(int i=0; i<num; i++)
	{
		cin>>aux;
		mapa[aux]++;
	}
	int inicio;
	cin>>inicio;
	//cout<<inicio<<endl;
	int mayor =99999,menor=99999;
	for(int i=inicio; i<=999; i++)
	{

		int copia=i;
		bool p=1;
		while(copia)
		{
			int m=copia%10;
			if(mapa[m])
			{
				p=0;
				break;
			}
			copia/=10;
		}
		if(p)
		{
			mayor=i;
			break;
		}
	}
	for(int i=inicio; i>=0; i--)
	{
		int copia=i;
		bool p=1;
		while(copia)
		{
			int m=copia%10;
			if(mapa[m])
			{
				p=0;
				break;
			}
			copia/=10;
		}
		if(i==0)
		{
			if(!mapa[i])
			{
				menor=i;
				break;
			}
		}
		else
		if(p)
		{
			menor=i;
			break;
		}
	}
	//cout<<mayor<<" "<<menor<<endl;
	if(menor==99999)
		menor=-99999;
	cout<<min(mayor-inicio, inicio-menor)<<endl;


	
}