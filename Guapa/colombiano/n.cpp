#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll cases,a,b,x,y,z;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>a>>b>>x>>y>>z;
		if(a>b)
		{
			ll c=a;
			a=b,
			b=c;
		}
		ll an=x+z;
		ll la=y+z+y+x+y;
		if(an<=a and la<=b)
			cout<<"POSSIBLE"<<endl;
		else
		{
			an=x+y+y;
			la=y+z+y+z;
			if(an<=a and la<=b)
				cout<<"POSSIBLE"<<endl;
			else
				cout<<"IMPOSSIBLE\n";
		}
	}
}