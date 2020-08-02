#include <bits/stdc++.h>
using namespace std;
#define max 1000005
#define inf 999999999
#define max_un 7
typedef long long ll; 
vector <pair<ll,ll>> vec;
ll total;
ll respuesta[max][max_un];
ll f(ll ind, ll estado, ll tiempo)
{
	ll sobra=tiempo-vec[ind].first;
	if(ind== total-1)
	{
		if(tiempo>0)
		{
			if(estado==1)
				return vec[ind].second;
			if(estado==2)
				return vec[ind].second-(vec[ind].second/2);
			return vec[ind].second-((vec[ind].second/4)*3);
		}
		else
			return vec[ind].second;
	}
	if(tiempo>0)
	{
		if(respuesta[ind][estado]!=-1)
				return respuesta[ind][estado];
		if(estado==6) 	
				return respuesta[ind][estado]=(vec[ind].second-((vec[ind].second/4)*3))+f(ind+1, 1, 120);
		
		if(estado==1)
				return respuesta[ind][estado]=vec[ind].second + min(f(ind+1, estado+1, sobra), f(ind+1, 1, 120 ));
		if(estado==2)
				return respuesta[ind][estado]= (vec[ind].second-(vec[ind].second/2))+ min(f(ind+1, estado+1, sobra), f(ind+1, 1, 120 ));
		else
				return respuesta[ind][estado]= (vec[ind].second-((vec[ind].second/4)*3))+ min(f(ind+1, estado+1, sobra), f(ind+1, 1, 120 ));
	}
	else
	{
		sobra=120 - vec[ind].first;
		if(respuesta[ind][1]!=-1)
			return respuesta[ind][1];
		else
			return respuesta[ind][1]=vec[ind].second + min(f(ind+1, estado+1, sobra), f(ind+1, 1, 120 )); 
	
	}
}
int main()
{
	ll d,c;
	memset(respuesta, -1, sizeof(respuesta));
	cin>>total;
	for(int i=0; i<total; i++)
	{
		cin>>d>>c;
		vec.push_back({d,c*100});
	}
	ll res=f(0, 1, 120);
	ll decimal=0;
	decimal+=(res%10);
	res/=10;
	decimal+=(res%10)*10;
	res/=10;
	cout<<res<<'.'<<decimal;
	if(decimal==0)
		cout<<0;
	cout<<endl;
}		