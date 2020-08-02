#include <bits/stdc++.h>
using namespace std;
#define maxi 100009
int main()
{
	long long n, suma,buscar,aux;
	vector<long long> arr,acc;

	while(scanf("%lld %lld ",&n,&suma)==2)
	{
		arr.clear();
		acc.clear();
		for(int i=0; i<n; i++)
		{
			scanf("%lld",&aux);
			if(i==0)
			{
				arr.push_back(aux);
				acc.push_back(aux);
			}
			else
			{
				arr.push_back(aux);
				acc.push_back(aux+acc[i-1]);
			}
		}
	
		bool ban=1;
		for(int i=0; i<n; i++)
		{
			buscar=suma-arr[i]+acc[i];
			
			auto it=lower_bound(acc.begin(), acc.end(), buscar);
			if(*it==buscar)
			{
				printf("%d %d\n",i+1,it-acc.begin()+1);
				ban=0;
				break;
			}
		}
		if(ban)
			printf("-1\n" );
	}
}