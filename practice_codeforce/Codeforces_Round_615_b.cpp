#include <bits/stdc++.h>
using namespace std;
int main()
{
	long double add=0;
	int num;
	cin>>num;
	for(int i=1; i<=num; i++)
	{
		add+=(long double)1/(long double)i;
		//cout<<(long double)1/(long double)i<<endl;
	}
	cout<<add<<endl;
}