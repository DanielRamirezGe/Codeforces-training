#include <bits/stdc++.h>
using namespace std;
#define maximo 200005
typedef long long ll;
ll tama,a,b;
int artistas;
set<pair<ll,int>> buscar;
vector<pair<ll,ll>> vec;
ll respuesta [maximo];
ll f(int indicador)
{
	if (indicador==artistas-1)
		return vec[indicador].second- vec[indicador].first+1;
	if(~respuesta[indicador])
		return respuesta[indicador];
	ll mayor=0,aux;
	ll fin=vec[indicador].second;
	//cout<<vec[indicador].first<<"  "<<vec[indicador].second<<endl;
	auto it=buscar.lower_bound({fin,indicador+1});
	ll r=0;
	if(it!=buscar.end() and it->first>fin)
		r=f(it->second);
	ll uno= vec[indicador].second-vec[indicador].first + 1 + r;
	ll dos=f(indicador+1);
	return respuesta[indicador]=max(uno, dos);
}
int main()
{
	scanf("%lld %d ",&tama,&artistas);
	for(int i=0; i<artistas; i++)
	{
		scanf("%lld %lld",&a,&b);
		vec.push_back({a,b});
	}
	sort(vec.begin(), vec.end());
	for(int i=0; i<artistas; i++)
		buscar.insert({vec[i].first, i});
	memset(respuesta, -1, sizeof(respuesta));
	
	ll may=f(0);
	//cout<<tama<<" "<<may<<endl;
	cout<<tama-may<<endl;
	return 0;
}