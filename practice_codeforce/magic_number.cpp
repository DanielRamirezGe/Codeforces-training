#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define maxi 2009
ll res[maxi][maxi];
ll m,d,a,b;
typedef long long ll;
long long res;
ll f(ll pos, ll suma)
{
	if(res[pos][suma]!=-1)
		return res[pos][suma];

	if((pos+1)%2==0)
	{
		ll act=0;
		suma= ((suma*10) + d)%mod;
		if(suma==0)
	}
}
int main()
{
	cin>>m>>d;
	cin>>a>>b;
	memset(res, -1, sizeof(res));
}