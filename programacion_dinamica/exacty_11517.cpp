#include <bits/stdc++.h>
using namespace std;
#define maxi_money 20009
#define maxi_bill 109
#define inf 99999999
int cost, n,busca;
int res[maxi_money][maxi_bill];
int res_2[maxi_money][maxi_bill];
vector<int> vec;
int f(int sum, int ind)
{
	if(ind==n)
	{
		if(sum<cost)
			return inf;
		return 0;
	}
	if(res[sum][ind]!=-1)
		return res[sum][ind];
	if(sum>cost)
		return 0;
	int a=f(sum+vec[ind], ind+1)+vec[ind];
	int b=f(sum, ind+1);
	return res[sum][ind]=min(a,b);
}
int fu(int suma, int ind)
{
	if(ind==n)
	{
		if(suma==busca)
			return 0;
		return inf;
	}
	if(suma>busca)
		return inf;
	if(res_2[suma][ind]!=-1)
		return res_2[suma][ind];
	int a=fu ( suma+ vec[ind] , ind +1) +1;
	int b=fu (suma , ind +1);
	return res_2[suma][ind]=min(a,b);
}
int main()
{
	int cases,aux;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>cost>>n;
		vec.clear();
		memset(res, -1, sizeof(res));
		memset(res_2, -1, sizeof(res_2));
		for(int i=0; i<n; i++)
		{
			cin>>aux;
			vec.push_back(aux);
		}
		busca=f(0,0);
		int cuantos=fu(0,0);
		cout<<busca<<" "<<cuantos<<endl;


	}
}