#include <bits/stdc++.h>
using namespace std;
#define maxi 100009
#define tod 29
long long res[tod][maxi];
int main()
{
	string cad;
	cin>>cad;
	
	memset(res, 0, sizeof(res));
	map<char,long long> mapa;
	for(long long i=0; i<cad.size(); i++)
	{
		//cout<<cad[i]<<" "<<(long long)cad[i]-'a'<<endl;
		res[cad[i]-'a'][i]=1;
		mapa[cad[i]]++;
	}


	for(long long i=0; i<tod; i++)
		for(long long j=cad.size()-1; j>=0; j--)
		{
			res[i][j]+=res[i][j+1];
		}
	long long maximo=0;
	for(long long i=0; i<tod; i++)
	{

		for(long long h=0; h<tod; h++)
		{
			long long tot=0;
			for(long long j=0; j<cad.size(); j++)
			{
				if(cad[j]-'a'==i)
				{
					tot+=res[h][j+1];
				}
			}
			if(tot>maximo)
				maximo=tot;
		}
		
	}
	for(auto x: mapa)
		if(x.second>maximo)
			maximo=x.second;
	cout<<maximo<<endl;
}