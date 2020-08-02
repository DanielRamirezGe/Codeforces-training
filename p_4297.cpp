#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,r,k;
	scanf("%d",&cases);
	for(int i=0; i<cases; i++)
	{
		scanf("%d %d",&r,&k);
		if(k&1)
		{
			long long p=(k/2);
			long long dos=r*r;
			long long res=((long long)1<<p)*dos;
			printf("%lldPI\n",res);
		}
		else
		{
			long long p=(k/2)+1;
			long long dos=r*r;
			long long res=((long long)1<<p)*dos;
			printf("%lld\n",res);

		}
	}
}