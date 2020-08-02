#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	long long a,b;
	scanf("%d",&cases);
	for(int i=0; i<cases; i++)
	{
		scanf("%lld %lld",&a,&b);
		printf("%lld\n",(a*b)/__gcd(a,b));
	}
}