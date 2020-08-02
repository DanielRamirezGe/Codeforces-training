#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num,aux;
	cin>>num; 
	map<int,int> mapa;
	mapa[0]=6;
	mapa[1]=2;
	mapa[2]=5;
	mapa[3]=5;
	mapa[4]=4;
	mapa[5]=5;
	mapa[6]=6;
	mapa[7]=4;
	mapa[8]=7;
	mapa[9]=6;
	for(int i=10;  ; i++)
	{
		int x=i;
		int suma=0;
		while(x)
		{
			int dig=x%10;
			suma+=mapa[dig];
			x/=10;
		}
		mapa[i]=suma;
		cout<<i<<" "<<suma<<endl;
	}
	vector<pair<int,int>> vec;
	pair<int,int> pon;
	for(auto a: mapa)
	{
		if(a.first!=0)
		{
			pon.first=a.second;
			pon.second=a.first;
			vec.push_back(pon);
		}
		
	}
	sort(vec.begin(),vec.end());
	
	//cout<<"   "<<vec.size()<<endl;
	for(int i=0; i<num; i++)
	{
		cin>>aux;
		int ind=0;
		for( ; ind<vec.size(); ind++)
		{
			if(vec[ind].first>aux)
				break;
		}
		int min=vec[ind].second;
		for( ; ind<vec.size(); ind++)
		{
			if(vec[ind].second<min)
				min=vec[ind].second;
		}
		cout<<min<<endl;
	}
}	