#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{

	n = 100000000;

	long long n;
	cin>>n;
	long long sum = 1;
	long long i=2;
	long long ant = 1;
	for( ; i*i < n; i++)
	{
		long long rest = (i*i) - ant;
		int add =0;
		if(rest%2==1)
			add = 1;
		sum = (sum + ( ( i-1) * (rest/2) )%mod + (( i) * ((rest/2)+add) ) %mod)%mod;
		ant = i*i;
	}

	6
	i= 2 - 3

	I*i=9
	long long res =  n - (ant);
	long long tope = i*i;
	long long mit =   ( (i*i) - ant ) /2; 
	if( res >= mit )
		sum = (sum + ( ( i-1) * (rest/2) )%mod +


}