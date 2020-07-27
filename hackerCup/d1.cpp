#include <bits/stdc++.h>
using namespace std;
#define mx 1000009
#define inf 9999999999999999ll
long long n,k;
long long cost[mx];
long long ans[mx];

int main()
{
	long long cases;
	cin>>cases;

	for(long long i=0; i<cases; i++)
	{
		
		multiset <long long> conj;

		cin>>n>>k;
		for(long long i=0; i<n; i++)
			cin>>cost[i];
		cost[n]=0;
		ans[n-1]=0;
		
		long long res;
		conj.insert(0);
		

		for(long long i=n-2; i>=0; i--){
			// for(auto x: conj)
			// 	cout<<x<<endl;
			auto mini = conj.begin();
			if(*mini == inf or cost[i]==0)
				ans[i]=inf;
			else
				ans[i] = cost[i] + *mini;

			//cout<<i<<"  "<<ans[i]<<endl;
			
			res=*mini;
			
			conj.insert( ans[i] );
			if( i+k <= n-1 ){
				auto l = conj.upper_bound(ans[i+k]);
				auto p = l;
				p--;
				conj.erase( p,l );
			}
		}

		cout<<"Case #"<<i+1<<": "<< (res != inf ? res : -1)<<endl;

	}
}