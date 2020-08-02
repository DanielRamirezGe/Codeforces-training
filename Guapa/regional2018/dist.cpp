	#include <bits/stdc++.h>
	using namespace std;
	#define max 10005
	#define inf 9999999999LL
	typedef long long ll;
	typedef pair<ll, pair<ll,ll>> ii;
	typedef pair< pair<ll,ll>, ll> iii;
	vector <ii> mat[max];
	ll cities,highways;
	pair <ll,ll> distancia[max];
	int main()
	{
		for(int i=0; i<max; i++)
		{
			distancia[i].first=inf;
			distancia[i].second=inf;
		}
		cin>>cities>>highways;
		int city_a,city_b, dis, cost;
		for(int i=0; i<highways; i++)
		{
			cin>>city_a>>city_b>>dis>>cost;
			mat[city_a].push_back({city_b,{dis,cost}});
			mat[city_b].push_back({city_a,{dis,cost}});
		}
		priority_queue <iii , vector<iii>, greater<iii>> pq;
		distancia[1].first=0;
		distancia[1].second=0;
		pq.push({{0,0},1});
		while(!pq.empty())
		{
			iii aux=pq.top();
			pq.pop();	
			int cit=aux.second;
			int d=aux.first.first;
			int c=aux.first.second;
			if(d > distancia[cit].first)
				continue;
			 for(auto a : mat[cit])
			 {
			 	int cit_aa=a.first;
			 	int d_a=a.second.first;
			 	int c_a=a.second.second;
			 	if( distancia[cit].first+d_a < distancia[cit_aa].first)
			 	{
			 		distancia[cit_aa].first=distancia[cit].first+d_a;
			 		distancia[cit_aa].second=c_a;
			 		pq.push( { {distancia[cit_aa].first, distancia[cit_aa].second} , cit_aa } );
			 	}
			 	else if(distancia[cit].first + d_a == distancia[cit_aa].first)
			 		if(distancia[cit_aa].second > c_a)
			 			distancia[cit_aa].second=c_a;
			 	
			}
		}
		ll con=0;
		for(int i=1; i<=cities; i++)
		{
			//cout<<distancia[i].first<<" ";
			con+=distancia[i].second;
		}
		//cout<<endl;
		cout<<con<<endl;
		

	}