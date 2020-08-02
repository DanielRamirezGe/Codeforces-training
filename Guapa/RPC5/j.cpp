#include <bits/stdc++.h>
using namespace std;
#define max 10000000
typedef long long ll;
int main()
{
	ll acu=0;
	vector<ll> arr;
	

	long long m;
	cin>>m;
	for(int i=m; i<=max; i++)
	{
		acu+=i;
		arr.push_back(acu);
		
	}
	//cout<<arr[1317140-m]<<" "<<arr[1571535-m]-arr[1317141-m]<<endl;
	for(long long i=0; i<max; i++)
	{
		long long busca = arr[i]+arr[i+1];

		auto it= lower_bound(arr.begin(),arr.end(),busca);
		if(*it==busca)
		{
			cout<<m<<" "<<i+1+m<<" "<<(it-arr.begin())+m<<endl;
			break;
		}

	}
}