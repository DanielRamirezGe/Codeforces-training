#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k,a,b;
	cin>>n>>k;
	vector<pair<long long,long long>> vec;
	for(long long i=0; i<n; i++)
	{
		cin>>a>>b;
		vec.push_back({b,a});
	}
	sort(vec.rbegin(),vec.rend());
	priority_queue <long long, vector<long long>, greater<long long>> menores;
	long long suma=0;
	long long may=0;
	for(long long i=0; i<k; i++)
	{
		menores.push(vec[i].second);
		suma+=vec[i].second;
		if(vec[i].first*suma > may)
		{
			may=vec[i].first*suma;
		}
	}
	for(long long i=k; i<n; i++)
	{
		auto it=menores.top();
		if(vec[i].second>it)
		{
			suma-=it;
			suma+=vec[i].second;
			menores.pop();
			menores.push(vec[i].second);
			if(vec[i].first*suma> may)
				may=vec[i].first*suma;
		}
		
	}
	cout<<may<<endl;
}