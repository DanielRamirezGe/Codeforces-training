#include <bits/stdc++.h>
using namespace std; 
int main()
{
	long long N,M,T,a,b,pi,po;
	scanf("%lld %lld %lld",&N,&M,&T);
	map < pair<long long, long long>, int> mapa;
	pair<long long, long long> aux;

	queue <pair<long long, long long> > q;
	long long con=0;
	for(long long i=0; i<N; i++)
	{
		scanf("%lld %lld",&a,&b);
		q.push({a,b});
		mapa[{a,b}]++;
		con++;
	}
	for(long long i=0; i<M; i++)
	{
		scanf("%lld %lld",&a,&b);
		mapa[{a,b}]++;
	}
	for(int i=0; i<T; i++)
	{
		long long ta=q.size();
		for(long long j=0; j<ta; j++)
		{
			aux=q.front();
			q.pop();
			pi=aux.first;
			po=aux.second;
			if(!mapa[{pi+1,po}])
			{
				mapa[{pi+1,po}]++;
				q.push({pi+1,po});
				con++;
			}
			if(!mapa[{pi-1,po}])
			{
				mapa[{pi-1,po}]++;
				q.push({pi-1,po});
				con++;
			}
			if(!mapa[{pi,po+1}])
			{
				mapa[{pi,po+1}]++;
				q.push({pi,po+1});
				con++;
			}
			if(!mapa[{pi,po-1}])
			{
				mapa[{pi,po-1}]++;
				q.push({pi,po-1});
				con++;
			}
		}
	}
	printf("%lld\n",con);

}