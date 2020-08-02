#include <bits/stdc++.h>
using namespace std; 
#define max 100000009
#define inf 999999999
int res[max];
int n,d,e;
int f(int cuanto)
{
	if(cuanto==0)
		return 0;
	if(cuanto < 0)
		return inf;
	if(res[cuanto]!=-1)
		return res[cuanto];
	int a=f(cuanto-d);
	int b=f(cuanto-(e*5));
	return res[cuanto]=min(min(a,b),cuanto);
}
int main()
{
	memset(res, -1, sizeof(res));
	cin>>n>>d>>e;
	int a=f(n-d);
	int b=f(n-(5*e));
	if(a==inf and b==inf)
	{
		a=n;
		b=n;
	}
	cout<<min(a,b)<<endl;
}