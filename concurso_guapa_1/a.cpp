#include <bits/stdc++.h>
using namespace std;
#define maxi 200009
typedef long long ll;
int  main()
{
	ll n, aux;
	cin>>n;
	map <ll,ll> mapa;
	ll tot=0;
	for(ll i=0; i<n; i++)
	{
		cin>>aux;
		mapa[aux]++;
		tot+=aux;
		//cout<<aux<<" "<<mapa[aux]<<endl;
	}
	
	ll acc[maxi];
	ll arr[maxi];

	memset(acc, 0, sizeof(acc));
	memset(arr, 0, sizeof(arr));

	for(ll i=0; i<maxi; i++)
	{
		if(mapa[i]!=0)
		{
			arr[i]=mapa[i]*i;
			
		}

	}


	acc[0]=arr[0];
	for(ll i=1; i<maxi; i++)
	{
		acc[i]=acc[i-1]+arr[i];
		//if(i<10)
		//cout<<acc[i]<<endl;
	}

	for(ll i=1; i<maxi; i++ )
	{
		ll a=acc[i-1];
		ll res=acc[i];
		if(a==(tot-res))
		{
			cout<<i<<endl;
			break;
		}
	}
}