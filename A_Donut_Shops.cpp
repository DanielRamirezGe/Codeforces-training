#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++){
		long long x,a,b;
		cin>>x >>a>>b;
		if( x < b )
			cout<<1<<" ";
		else
			cout<<-1<<" ";

		if( x*a > b)
			cout<<a<<endl;
		else
			cout<<-1<<endl;

	}
}