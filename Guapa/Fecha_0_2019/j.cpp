#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,k, n;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>k>>n;
		cout<<k<<" "<<(((n+1)*(n+2))/2)-1<<'\n';
	}
}