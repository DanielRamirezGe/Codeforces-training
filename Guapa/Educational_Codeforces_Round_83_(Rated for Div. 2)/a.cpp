#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin>>a;
	for(int i=0; i<a; i++)
	{
		int x,y;
		cin>>x>>y;
		if(x%y==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}