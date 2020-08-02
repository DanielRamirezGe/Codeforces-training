#include <bits/stdc++.h>
using namespace std;
#define maxi 100009
#define inf 9999999999999999LL
typedef long long ll;
typedef pair<ll,ll> llll;
vector <llll> mat[maxi];
priority_queue < llll, vector<llll>, greater<llll>> pq;
ll origen[maxi];
ll fin[maxi];
int main()
{
	int x,y,a,b,c,n,e;
	cin>>n>>e;
	vector< pair< pair<int,int> , int > > vec;
	for(int i=0; i<maxi; i++)
	{
		origen[i]=inf;
		fin[i]=inf;
	}
	for(int i=0; i<e; i++)
	{
		cin>>a>>b>>c;
		mat[a].push_back({c,b});
		mat[b].push_back({c,a});
		vec.push_back({{a,b},c});	
	}
	cin>>x>>y;
	origen[x]=0;
	pq.push({0,x});
	llll aux;
	while(!pq.empty())
	{
		aux=pq.top();
		pq.pop();
		ll d=aux.first;
		ll u=aux.second;
		if(d>origen[u])
			continue;
		for(auto a: mat[u])
		{
			if(origen[u]+a.first < origen[a.second])
			{
				origen[a.second]=origen[u]+a.first;
				pq.push({origen[a.second],a.second});
			}
		}
	}
	fin[y]=0;
	pq.push({0,y});
	while(!pq.empty())
	{
		aux=pq.top();
		pq.pop();
		ll d=aux.first;
		ll u=aux.second;
		if(d > fin[u])
			continue;
		for(auto a: mat[u])
		{
			if(fin[u]+a.first < fin[a.second])
			{
				fin[a.second] = fin[u]+a.first;
				pq.push({fin[a.second],a.second});
			}
		}
	}
	ll mini=origen[y];
	int aris=0;
	for(int i=0; i<vec.size(); i++)
	{
		int aa=vec[i].first.first;
		int bb=vec[i].first.second;
		int cc=vec[i].second;
		if(origen[aa]+cc+fin[bb]==mini or origen[bb]+cc+fin[aa]==mini)
			aris++;
	}
	cout<<aris<<endl;
}