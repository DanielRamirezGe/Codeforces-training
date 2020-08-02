	#include <bits/stdc++.h>
	using namespace std;
	#define max 1000005
	bool criba[max];
	bool tocado[max];
	int tree[max];
	set <int> primos;
	int LSO(int n)
	{
		return n&-n;
	}
	long long  rqs(long long b)
	{
		long long suma=0;
		int ori=b;
		for( ; b; b-=LSO(b))
		{
			suma+=tree[b];
		}
		return suma;
	}
	void actualizar (long long k, long long v)
	{
		for( ; k<max; k+=LSO(k))
		{
			tree[k]+=v;
		}
	}
	void criva()
	{
		for(long long i=2; i<max; i++)
		{
			if(!criba[i])
			{
				for(long long j=i*i; j<max; j+=i )
					criba[j]=true;
				primos.insert(i);
			}
			//cout<<i<<endl;
		}
	}
	int main()
	{
		memset(criba, 0, sizeof(criba));
		memset(tocado, 0, sizeof(tocado));
		memset(tree, 0, sizeof(tree));
		int queries, n,k;
		cin>>queries;
		map <int,long long> mapa;
		vector<pair< pair<int,int> ,int > > vec;
		for(int i=0; i<queries; i++)
		{
			cin>>n>>k;
			vec.push_back({{k,n},i});

		}
		criva();

		sort(vec.rbegin(), vec.rend());
		for(int i=2; i<max; i++)
			actualizar(i,1);

		int hasta=max;
		int quedo;	
		for(int i=0; i<queries; i++)
		{
			auto buscar=primos.upper_bound(vec[i].first.first);
			//cout<<vec[i].first.first<<"   "<<*buscar<<endl;
			quedo=*buscar;
			if(hasta> *buscar)
			{

				while(buscar!= primos.end() and *buscar < hasta )
				{
					for(int i=*buscar; i<max; i+=*buscar)
					{
						if(!tocado[i])
						{
							tocado[i]=true;
							actualizar( i,-1);
						}

					}
					
					buscar++;
				}
				hasta=quedo;
				
			}
			mapa[vec[i].second]=rqs(vec[i].first.second);

		}
		for(auto a: mapa)
			cout<<a.second<<endl;
	}	