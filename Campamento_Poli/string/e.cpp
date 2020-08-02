#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define base 47
typedef long long ll;
ll fhash(string cad)
{
	ll hash=0;
	ll p=1;
	ll suma;
	for(int i=0; i<cad.size(); i++)
	{
		suma=(cad[i]-'a'+1)*p;
		p=(p*base)%mod;
		hash=(hash+suma)%mod;
	}
	return hash;
}
int main()
{
	int dic, que;
	cin>>dic>>que;
	string cad, aux;
	ll hash;
	set < pair<ll, string> > mapa;
	for(int i=0; i<dic; i++)
	{
		cin>>cad;
		ll hash=fhash(cad);
		ll p=1,aux=0, resta, suma;
		for(int i=0; i<cad.size(); i++)
		{
			resta=(cad[i]-'a'+1)*p;
			suma= ('z'-'a'+1)*p;
			aux= (hash-resta+mod)%mod;
			aux= (aux+suma)%mod;
		
			mapa.insert({aux,cad});
			p=(p*base)%mod;
		}
	}
	
	for(int i=0; i<que; i++)
	{
		cin>>cad;
		ll hash=fhash(cad);
		ll p=1,aux=0, resta, suma;
		bool ban=1;
		for(int i=0; i<cad.size() and ban; i++)
		{
			resta=(cad[i]-'a'+1)*p;
			suma= ('z'-'a'+1)*p;
			aux= (hash-resta+mod)%mod;
			aux= (aux+suma)%mod;
			p=(p*base)%mod;
			
			auto it=mapa.lower_bound({aux,cad});
			
			if( it->first == aux)
			{
				auto dos=it;
				while(dos!=mapa.end() and dos->first== aux and ban)
				{
					if(dos->second!= cad)
					{
						cout<<"YES\n";
						ban=0;
						break;

					}
					dos++;
				}
				dos=it;
				while(dos!=mapa.begin() and dos->first== aux and ban	)
				{
					if(dos->second!= cad)
					{
						cout<<"YES\n";
						ban=0;
						break;
					}
					dos--;
				}
			}
			else
			{
				if(it!=mapa.begin())
				{
					it--;
					if(it->first==aux)
					{
						auto dos=it;
						while(dos!=mapa.end() and dos->first== aux and ban)
						{
							if(dos->second!= cad)
							{
								cout<<"YES\n";
								ban=0;
								break;
							}
							dos++;
						}
						dos=it;
						while(dos!=mapa.begin() and dos->first== aux and ban)
						{
							if(dos->second!= cad)
							{
								cout<<"YES\n";
								ban=0;
								break;
							}
							dos--;
						}
					}
				}
			}
		}
		if(ban)
			cout<<"NO\n";
	}
	
}