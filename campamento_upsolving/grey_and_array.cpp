#include <bits/stdc++.h>
using namespace std;
#define maxi 100009
typedef long long ll;
int main()
{
	ll n,m,k, aux,a,b;
	cin>>n>>m>>k;
	vector <ll> origin;
	for(ll i=0; i<n; i++)
	{
		cin>>aux;
		origin.push_back(aux);
	}
	ll acc[maxi];
	memset(acc, 0, sizeof(acc));
	vector <pair<pair<ll,ll>,ll>> vec;
	ll todo[maxi];
	memset(todo, 0, sizeof(todo));
	for(ll i=0; i<m; i++)
	{
		cin>>a>>b>>aux;
		vec.push_back({{a,b},aux});
	}
	for(ll i=0; i<k; i++)
	{
		cin>>a>>b;
		//cout<<a<<" "<<b<<endl;
		acc[a]++;
		acc[b+1]--;
	}
	// for(ll i=1; i<10; i++)
	// 	cout<<acc[i]<<" ";
	// cout<<endl;
	for(ll i=1; i<maxi; i++)
		acc[i]+=acc[i-1];
	

	// for(ll i=1; i<10; i++)
	// 	cout<<acc[i]<<" ";
	// cout<<endl;
	for(ll i=0; i<m; i++)
	{
		todo[vec[i].first.first]+=vec[i].second*acc[i+1];
		todo[vec[i].first.second+1]-=vec[i].second*acc[i+1];
	}
	for(ll i=1; i<maxi; i++)
		todo[i]+=todo[i-1];
	for(ll i=0; i<n; i++)
		origin[i]+=todo[i+1];
	
	for(ll i=0; i<n; i++)
	{
		cout<<origin[i];
		if(i!=n-1)
			cout<<" ";
		else
			cout<<endl;
	}

}