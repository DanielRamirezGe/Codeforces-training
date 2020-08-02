#include <bits/stdc++.h>
using namespace std;
#define maxi 100000
typedef long long ll;
bool criba [maxi];
vector <int> prim;
void c()
{
	prim.push_back(2);
	for(ll i=3; i<maxi; i+=2)
	{
		if(!criba[i])
		{
			for(ll j=i*i; j<maxi;  j+=i )
				criba[j]=1;
			prim.push_back(i);
		}
	}

}
ll dig(int num)
{
	ll suma=0;
	while(num)
	{
		suma+=(num%10);
		num/=10;
	}
	return suma;
}
ll fac(int num)
{
	int ind=0;
	int p=prim[ind];
	vector<int> vec;
	ll suma=0;
	ll aux=num;
	while(p*p<=num)
	{
		while(num%p==0)
		{	
			suma+=dig(p);
			num/=p;
		}
		ind++;
		p=prim[ind];
	}
	if(num!=1)
		suma+=dig(num);
	if(num==aux)
		return 0;
	return suma;

}

bool fun(int num)
{
	ll di=dig(num);
	//cout<<di<<endl;
	ll fa=fac(num);
	//cout<<fa<<endl;
	return (di==fa );
}
int main()
{
	int cases,num;
	cin>>cases;
	memset(criba, 0, sizeof(criba));
	c();
	for(int i=0; i<cases; i++)
	{
		cin>>num;
		for(int i=num+1; 1 ; i++)
		{
			bool ban=fun(i);
			if(ban)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
}