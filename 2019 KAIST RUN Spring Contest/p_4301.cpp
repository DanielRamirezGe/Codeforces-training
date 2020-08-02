#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define max_l 505
int c,v,l,k;
long long res[max_l][2];
bool ban;
long long f(int estado, int ind)
{
//	cout<<estado<<" "<<ind<<endl;
	if(ind==l)
		if(estado==1)
			return v;
		else
			return 0;
	if(res[ind][estado]!=-1)
		return res[ind][estado];
	if(estado==0)
	{
		long long resp=c*f(1,ind+1);
		if(resp>=mod)
			ban=1;
		return res[ind][estado]=resp%mod;
	}
	long long resp=(v*f(1, ind+1));
	if(resp>=mod)
			ban=1;
	resp=((resp%mod)+(v*f(0, ind+1)));
	if(resp>=mod)
			ban=1;
	resp=resp%mod;
	 return res[ind][estado]=resp;

}
int main()
{
	int cases;
	
	scanf("%d",&cases);
	for(int i=0; i<cases; i++)
	{
		ban=0;
		memset(res, -1, sizeof(res));
		scanf("%d %d %d %d",&c,&v,&l,&k);
		long long tot=f(0,1)+f(1,1);
		//cout<<f(0,1)<<" "<<f(1,1)<<endl;
		if(tot>=mod)
		ban=1;
		tot=tot%mod;
		if(ban)
			printf("%lld Accepted\n",tot);
		else
		{
			if(tot>=k)
				printf("%lld Accepted\n",tot);
			else
				printf("%lld Rejected\n",tot);
		}	
	}
}