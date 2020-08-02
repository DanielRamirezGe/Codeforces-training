#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	a-=2*c;
	b-=2*c;
	if(a<0 or b<0)
		cout<<0<<endl;
	else
		cout<<a*b<<endl;
}