#include <bits/stdc++.h>
using namespace std;
#define max 10000000000LL
typedef long long ll;
int main()
{
	ll anterior=1;
	ll ancho,buscar;
	vector <ll> vec;
	set < pair<ll,ll> > con;
	con.insert({1,0});
	vec.push_back(1);
	ll indice=0;
	for(ll i=3; anterior<=max; i+=2)
	{
		indice++;
		ll x=(i*4)-4;
		vec.push_back(i);
		anterior=anterior+x;
		con.insert({anterior,indice});
	}
	while(scanf("%lld%lld",&ancho,&buscar)==2 and ancho!=0 and buscar!=0)
	{
		auto it=con.lower_bound({buscar, 0});
		ll  cantidad=it->first;
		//cout<<cantidad<<" "<<buscar<<endl;
		ll indice=it->second;
		ll sobra=cantidad-buscar;
		int esquina=0;
		if(vec[indice]-1!=0)
			esquina=sobra/(vec[indice]-1); 
		ll avanzar=(cantidad-(vec[indice]-1)*esquina)-buscar;
		ll i,j;
		if(esquina==0)
		{
			i=j=((ancho/2)+1)+indice;
			i-=avanzar;
		}
		if(esquina==1)
		{
			j=((ancho/2)+1)+indice;
			i=((ancho/2)+1)-indice;
			j-=avanzar;
		}
		if(esquina==2)
		{
			i=j=((ancho/2)+1)-indice;
			i+=avanzar;
		}
		if(esquina==3)
		{
			i=((ancho/2)+1)+indice;
			j=((ancho/2)+1)-indice;
			j+=avanzar;
		}
		cout<<"Line = "<<i<<", column = "<<j<<"."<<endl;
	}	
}