#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maximo 50
ll res[maximo];
int hasta;
ll f(int num)
{
	if(num>hasta)
		return 0;
	if(num==hasta)
		return 1;
	if(res[num]!=-1)
		return res[num];
	ll a=0,b=0;
	a=f(num+2)*4;
	b=f(num+1);
	return res[num]=a+b;

}
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>hasta;
		memset(res, -1, sizeof(res));
		cout<<f(0)<<endl;
	}
}