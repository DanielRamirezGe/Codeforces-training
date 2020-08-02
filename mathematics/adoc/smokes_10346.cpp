#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		int tot=n;
		while(n>=k)
		{
			int nuevos=n/k;
			tot+=nuevos;
			n=nuevos+n%k;
		}
		cout<<tot<<endl;
	}
}