#include <bits/stdc++.h>
using namespace std;
#define maxi 1000000
#define inf 9999999
bool  criba[maxi];
vector <int> prim;
typedef long long ll;
ll _gcd(ll u, ll v) {
    while (v != 0) {
        ll r = u % v;
        u = v;
        v = r;
    }
    return u;
}
void c()
{

	prim.push_back(2);
	prim.push_back(3);
	for(ll i=3; i<maxi; i+=2)
	{
		if(!criba[i])
		{
			prim.push_back(i);
			for(ll j=i*i; j<maxi; j+=i)
				criba[j]=1;
		}
	}
}
vector<ll> f(ll n)
{
	vector<ll> fac;
	ll ind=0, p=prim[ind];
	while(p*p <=n)
	{
		while(n%p==0)
		{
			n/=p;
			fac.push_back(p);
		}
		p=prim[++ind];
	}
	if(n!=1)
		fac.push_back(n);
	return fac;

}
int main()
{
	ll n,aux;
	cin>>n;
	vector<ll> arr;
	for(int i=0; i<n; i++)
	{
		cin>>aux;
		arr.push_back(aux);
	}
	memset(criba, 0, sizeof(criba));
	c();

	vector<ll> v;
	map <int,int>mapa;
	ll gcd=arr[0];

	for(int i=0; i<n; i++)
	{
		gcd=__gcd(gcd,arr[i]);
	}
	//cout<<gcd<<endl;
	v=f(gcd);
	for(int i=0; i<v.size(); i++)
	{
		//cout<<v[i]<<endl;
		mapa[v[i]]++;
	}
	ll res=1;
	for(auto a: mapa)
		res*=(a.second+1);	
	cout<<res<<endl;

}
