#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,a,b,c,n,s;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>a>>b>>n>>s;
		int res=s/n;
		if(res<=a)
		{
			int mod=s%n;
			if(mod<=b)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else
		{
			int mod=s-(n*a);
			if(mod<=b)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}

}