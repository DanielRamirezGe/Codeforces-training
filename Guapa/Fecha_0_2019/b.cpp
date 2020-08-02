#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,k, aux,base;
	long long num, tot=0;
	cin>>cases;	
	for(int i=0; i<cases; i++)
	{
		tot=0;
		cin>>k>>base>>num;
		while(num)
		{
			aux=num%base;
			tot+=(aux*aux);
			num/=base;
		}
		cout<<k<<" "<<tot<<'\n';

	}
}