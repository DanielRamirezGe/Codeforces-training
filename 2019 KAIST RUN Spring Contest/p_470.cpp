#include <bits/stdc++.h>
using namespace std;
#define maximo 100000
int main()
{
	int cases,n,q;
	long long tot=0,buscar,res;
	int arr[maximo];
	scanf("%d",&cases);
	for(int i=0; i<cases; i++)
	{
		scanf("%d %d",&n,&q);
		for(int j=0; j<n; j++)
			scanf("%d",&arr[j]);

		for(int j=0; j<q; j++)
		{
			tot=0;
			res=0;
			scanf("%d",&buscar);
			int menor=0,mayor=0;
			while(menor<n)
			{
				if(tot<buscar)
				{
					if(mayor<n)
					{
						tot+=arr[mayor];
						mayor++;
					}
					else
						break;
				}
				else
					if(tot>buscar)
					{
						if(menor<n)
						{
							tot-=arr[menor];
							menor++;
						}
						else
							break;
					}
					else
					{
						int left=1, ri=1;
						int ind=mayor;
						while(ind<n and arr[ind]==0)
						{
							ind++; 
							ri++;
						}
						mayor=ind;
						ind=menor;
						while(ind<n and tot-arr[ind]==buscar)
						{
							left++;
							ind++;
						}
						res+=left*ri;
						if(mayor<n)
						{
							tot+=arr[mayor];
							mayor++;
						}
						else
							break;
					}
			}
			printf("%lld",res);
			if(j!=q-1)
				printf(" ");
		}
		printf("\n");
	}
}