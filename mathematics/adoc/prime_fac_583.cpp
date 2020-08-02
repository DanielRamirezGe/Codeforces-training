#include <bits/stdc++.h>
using namespace std;
#define maxi 999999
typedef long long ll;
bool criba[maxi];
vector<int> primos;
void e_p()
{
	primos.push_back(2);

	for(ll i=3; i<maxi; i+=2)
	{
		if(!criba[i])
		{
			primos.push_back(i);
			for(ll j=i*i ; j<maxi ; j+=i)
				criba[i]=1;
		}
	}
}
vector<int> p_f(int n)
{
	vector<int> res;
	if(n<0)
	{
		n*=-1;
		res.push_back(-1);
	}
	
	ll ind=0, actual=primos[ind];
	while(actual*actual<=n)
	{
		while(n%actual==0)
		{
			n/=actual;
			res.push_back(actual);
		}
		actual=primos[++ind];
	}
	if(n!=1)
		res.push_back(n);
	return res;
}
int main()
{
	int num;
	memset(criba, 0, sizeof(criba));
	e_p();
	while(cin>>num and num!=0)
	{
		vector<int> imp;
		imp=p_f(num);
		cout<<num<<" = ";
		int i=0;
		
		for( ; i<imp.size(); i++)
		{
			cout<<imp[i];
			if(i!=imp.size()-1)
				cout<<" x ";
		}
		cout<<endl;
	}
}