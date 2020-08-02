#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,a,b;
	scanf("%d",&cases);
	for(int i=0; i<cases; i++)
	{
		scanf("%d %d",&a,&b);
		double res=a*log10(2) + b*log10(5);
		int tot=res;
		printf("%d\n",tot+1);
		
	}
}