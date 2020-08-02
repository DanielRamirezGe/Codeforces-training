#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long cases,a,b;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>a>>b;
		//cout<<a<<" "<<b+1<<endl;
		if(a>b+1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}