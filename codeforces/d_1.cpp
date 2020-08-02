#include <bits/stdc++.h>
using namespace std;
int main()
{
	int tab,gamers,cards ;
	cin>>tab>>gamers;
	string cad,color;
	int num;
	vector <string> vec;
	int especial;
	for(int i=1; i<tab; i++)
	{
		cin>>cad;
		vec.push_back(cad);
	}
	cin>>cards;
	vector < pair<int,string> > tod;
	for(int i=0; i<cards; i++)
	{
		cin>>num>>color;
		if(num==3)
		{
			especial=tod.size();
		}
		tod.push_back({num,color});
	}
	map <int,int> mapa;
	for(int i=0; i<gamers; i++)
		mapa[i]=-1;
	int con_car=0, con_jug=0;
	int ganador, minimo=9999999;
	bool ban=1;
	for(int i=0; i<gamers; i++)
	{
		con_car=0;
		int estoy=-1;
		bool ban=1;
		int res=99999;
		int turns=1;
		for(int j=0; ban and j<10000; j++)
		{
			turns++;
			auto aux=tod[con_car];
			con_car=(con_car+gamers)%cards;
			if(aux.first==3)
			{
				estoy=especial;
			}
			else
			{
				estoy++;
				for(; ; estoy++)
				{
					if(estoy>=tab-1)
					{
						res=turns;
						ban=0;
						break;
					}
					if(aux.second==vec[estoy])
					{
						if(aux.first!=1)
							aux.first--;
						else
							break;
					}
				}
			}
		}
		cout<<res<<" "<<minimo<<" "<<i+1<<endl;
		if(res<minimo)
		{

			minimo=res;
			ganador=i+1;
		}

	}
	
	
	cout<<ganador<<endl;
}