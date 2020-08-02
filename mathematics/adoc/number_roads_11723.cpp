#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,r;
	int con=1;
	while(cin>>n>>r and (n!=0 and r!=0))
	{
		int res=n/r;
		if(n%r==0)
			res--;
		if(res>26)
			cout<<"Case "<<con<<": impossible"<<endl;
		else
			cout<<"Case "<<con<<": "<<res<<endl;
		con++;
	}
}