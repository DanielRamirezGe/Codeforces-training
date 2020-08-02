#include <bits/stdc++.h>
using namespace std;
#define maxi 10000009
typedef long long ll;
bitset<maxi> criba;
vector <ll> primos;

void c()
{
	primos.push_back(2);
	for(ll i=3; i<maxi; i++)
	{
		if(!criba[i])
		{
			for(ll j=i*i; j<maxi; j+=i)
				criba[j]=1;
			primos.push_back(i);
		}
	}
}
ll saca(long long n)
{
	ll ind=0;
	ll p=primos[ind];
	map<ll,ll> mapa;
	while(p*p<=n)
	{

		while(n%p==0)
		{
			//cout<<p<<endl;
			n/=p;
			mapa[p]++;
		}
		p=primos[++ind];
	}
	if(n!=1)
		mapa[n]++;
	ll mul=1;
	for(auto a: mapa)
		mul*=(a.second+1);
	return mul;
}
int main()
{
	criba.reset();
	c();
	long long n;
	while(cin>>n and n!=0 )
	{

		ll a=saca(n);
		//cout<<a<<endl;
		if(a%2==0)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
		//cout<<n<<endl;
	}
	//cout<<n<<endl;
}