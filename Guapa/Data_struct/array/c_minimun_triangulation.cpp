#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long res=0;
	int n;
	cin>>n;
	for(int i=2; i<n; i++)
		res+=(i*(i+1));
	cout<<res<<endl;
}