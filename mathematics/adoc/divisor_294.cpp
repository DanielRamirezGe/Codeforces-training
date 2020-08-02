#include <bits/stdc++.h>
using namespace std;
#define maxi 1000000
bool criba[maxi];
vector<long long> primo;
vector<long long> factores;
void c()
{
	primo.push_back(2);
	criba[2]=1;
	for(long long i=3;i<maxi; i+=2)
	{
		if(!criba[i])
		{
			for(long long j=i*i; j<maxi; j+=i)
				criba[j]=1;
			primo.push_back(i);
		}
	}

}
void primeFactor(long long N)
{
	long long index=0, pri=primo[index];
	//cout<<N<<endl;
	long long original=N;
	while(pri*pri<=N)
	{
		while(N%pri==0)
		{
			//cout<<".... "<<N<<endl;
			N/=pri;
			factores.push_back(pri);
			
		}
		pri=primo[++index];
		//cout<<"p:    "<<pri<<endl;

	}
	if(N!=1)
		factores.push_back(N);

}
int  main()
{
	long long a,b,cases;
	cin>>cases;
	map<long long,long long> mapa;
	memset(criba, 0, sizeof(criba));
	c();
	
	for(long long i=0; i<cases; i++)
	{
		cin>>a>>b;
		long long maximo=0, num;
		for(long long j=a; j<=b; j++)
		{ 
			mapa.clear();
			factores.clear();
			primeFactor(j);
			for(auto x: factores)
				mapa[x]++;
			long long respuesta=1;
			for(auto c: mapa)
				respuesta*=(c.second+1);
			if(respuesta>maximo)
			{
				maximo=respuesta;
				num=j;
			}

		}
		cout<<"Between "<<a<<" and "<<b<<", "<<num<<" has a maximum of "<<maximo <<" divisors."<<endl;
	}
}