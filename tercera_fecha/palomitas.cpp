#include <bits/stdc++.h>
using namespace std;
#define maxi 1000000009ll
vector<long long> times;
long long n,c,t, aux;
bool f(long long busca)
{
	long long con=1;
	long long suma=0;
	long long limite=busca*t;
	for(long long i=0; i<times.size(); i++)
	{
		if(times[i]>limite)
			return 0;
		if(suma+times[i]>limite)
		{
			con++;
			suma=times[i];
		}
		else
		{
			suma+=times[i];
		}
	}
	if(con>c)
		return 0;
	return 1;
}

int main()
{

	cin>>n>>c>>t;
	for(long long i=0; i<n; i++)
	{
		cin>>aux;
		times.push_back(aux);
	}
	long long l=1;
	long long r=maxi;
	long long mit;
	mit=l+((r-l)/2);
	int mini=maxi;
	while(l<r)
	{
		
		bool res=f(mit);
		if(res)
		{
			if(mit<mini)
				mini=mit;
			r=mit;
		}
		else
			l=mit+1;
		mit=l+((r-l)/2);
	}
	cout<<mit<<endl;
}
