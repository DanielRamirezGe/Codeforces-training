#include <bits/stdc++.h>
using namespace std;
#define base_uno 127
#define base_dos 131
#define mod 1000000009ll
typedef long long ll;
vector<ll> uno,dos;
ll num,aux;
map <pair<ll, ll>,int> mapa;

bool f(ll tam)
{
	mapa.clear();
	ll res=0,res_dos=0, base=1, bb=1;
//	cout<<"empieza"<<endl;
	for(int i=0; i<tam; i++)
	{

		res=(((res*base_uno)%mod)+uno[i])%mod;
		res_dos=(((res_dos*base_dos)%mod)+uno[i])%mod;
		// if(tam==9 and i>0)
		//  	cout<<"["<<uno[i-1]<<" "<<uno[i]<<"] "<<res<<"  "<<base<<endl;
		if(i!=tam-1)
		{
			base=(base*base_uno)%mod;
			bb=(bb*base_dos)%mod;
		}	
	}
	mapa[{res,res_dos}]++;
	ll inicial=1;
	for(ll i=tam; i<num; i++)
	{
		res=(res-(uno[i-tam]*base)%mod+mod)%mod;
		res=(((res*base_uno)%mod)+uno[i])%mod;

		res_dos=(res_dos-(uno[i-tam]*bb)%mod+mod)%mod;
		res_dos=(((res_dos*base_dos)%mod)+uno[i])%mod;
		 // if(tam==9)
		 // 	cout<<"["<<uno[i-1]<<" "<<uno[i]<<"] "<<res<<"  "<<base<<endl;
		mapa[{res,res_dos}]++;
	}
	//cout<<"dos"<<endl;
	res=0,base=1,res_dos=0,bb=1;
	for(ll i=0; i<tam; i++)
	{
		res=(((res*base_uno)%mod)+dos[i])%mod;
		res_dos=(((res_dos*base_dos)%mod)+dos[i])%mod;
		 // if(tam==9 and i>0)
		 // 	cout<<"["<<dos[i-1]<<" "<<dos[i]<<"] "<<res<<"  "<<base<<endl;
		
		if(i!=tam-1)
		{
			base=(base*base_uno)%mod;
			bb=(bb*base_dos)%mod;
		}
	}
	if(mapa[{res,res_dos}])
		return 1;
	inicial=1;
	for(ll i=tam; i<num; i++)
	{
		res=(res-(dos[i-tam]*base)%mod+mod)%mod;
		res=(((res*base_uno)%mod)+dos[i])%mod;

		res_dos=(res_dos-(dos[i-tam]*bb)%mod+mod)%mod;
		res_dos=(((res_dos*base_dos)%mod)+dos[i])%mod;
		 // if(tam==9)
		 // 	cout<<"["<<dos[i-1]<<" "<<dos[i]<<"] "<<res<<"  "<<base<<endl;
		
		if(mapa[{res,res_dos}])
			return 1;
	}
	return 0;
}
int main()
{
	
	cin>>num;
	for(ll i=0; i<num; i++)
	{
		cin>>aux;
	
		uno.push_back(aux);
	}

	for(ll i=0; i<num; i++)
	{
		cin>>aux;

		dos.push_back(aux);
	}
//	cout<<"hasta aqui"<<endl;
	ll l=1, r=num, mit=l+(r-l)/2;
	if(f(1))
	{
		
		while(l<r)
		{
			//cout<<"    "<<mit<<" "<<l<<" "<<r<<endl;
			if(l+1==r)
			{ 	
				if(f(r))
				{
					mit=r;
					break;
				}
				else
				{
					mit=l;
					break;
				}
			}
			bool res=f(mit);
			if(res)
				l=mit;
			else
				r=mit-1;
			mit=l+(r-l)/2;
		}
		cout<<mit<<endl;
	}
	else
		cout<<0<<endl;
}