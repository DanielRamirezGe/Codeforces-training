#include <bits/stdc++.h>
using namespace std;
#define maxi 20000009
typedef long long ll;
bitset<maxi> crib;
vector<int> primo;
vector<pair<int,int>> twi;
void c()
{
	primo.push_back(2);
	for(ll i=3; i<maxi; i+=2)
	{
		if(!crib[i])
		{
			for(ll j=i*i; j<maxi; j+=i)
				crib[j]=1;
			primo.push_back(i);
		}
	}

}
void f()
{
	for(int i=1; i<primo.size(); i++)
	{
		if(primo[i-1]+2==primo[i])
			twi.push_back({primo[i-1], primo[i]});
	}
}
int main()
{
	crib.reset();
	c();
	f();
	int n;
	while(cin>>n)
	{
		cout<<"("<<twi[n-1].first<<", "<<twi[n-1].second<<")\n";
	}

}