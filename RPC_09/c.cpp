#include <bits/stdc++.h>
using namespace std;
#define maxi 1009
#define inf 9999999999999L
typedef long long ll;
ll res[maxi][maxi];
ll tot;
ll n, m, t;
vector <ll> mat[maxi];
pair<ll,ll> arr[maxi];
ll f(ll nodo, ll tiempo)
{
	if(tiempo==tot and nodo==1)
		return 0;
	if(tiempo>tot)
		return inf;
	if(res[nodo][tiempo]!=-1)
		return res[nodo][tiempo];

	ll uno=f(nodo, tiempo + arr[nodo].first)+arr[nodo].second;
	ll dos=inf;
	ll aux;
	for(auto a: mat[nodo])
	{
		aux=f(a, tiempo + t + arr[a].first)+arr[a].second;
		if(aux<dos)
			dos=aux;
	}
	return res[nodo][tiempo]=min(uno,dos);

}
int main()
{
	cin>>tot;
	cin>>n>>m>>t;
	ll a,b;
	for(ll i=1; i<=m; i++)
	{
		cin>>a>>b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	for(ll i=1; i<=n; i++)
	{
		cin>>a>>b;
		arr[i].first=a;	
		arr[i].second=b;
	}
	memset(res, -1, sizeof(res));
	ll p=f(1,arr[1].first)+arr[1].second;
	if(p>=inf or arr[1].first==tot )
		cout<<"It is a trap."<<endl;
	else
		cout<<p<<endl;
}