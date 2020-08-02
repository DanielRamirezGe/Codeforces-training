#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int n;
		cin>>n;
		n-=4;
		if(n%4 == 0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}