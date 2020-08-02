#include <bits/stdc++.h>
using namespace std;
#define maxi 15
#define inf 9999999
#define maxi_res 5000
int n;
int cases,a,x,y,b;
vector <pair<int,int>> mat[maxi];
int ok;
int res[maxi][maxi_res];
int f(int nodo, int bit)
{
	if(bit==ok)
	{
		int d=mat[0][nodo].first;
		return d;
	}
	if(res[nodo][bit]=!-1)
		return res[nodo][bit];
	int tot=inf;
	for(auto a: mat[nodo])
	{

		int i=a.second;
		int d=a.first;
		if(!(bit & (1<<i)))
		{
			bit|=(1<<i);
			int p=f(i, bit);
			bit-=(1<<i);
			if(p+d < tot)
				tot=p+d;
		}
	}
	return res[nodo][bit]=tot;
}

int main()
{

	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		for(int i=0; i<maxi; i++)
			mat[i].clear();
		cin>>a>>b;
		cin>>a>>b;
		cin>>n;
		ok = (1<<(n+1))-1;
		vector <pair<int,int>> vec;
		vec.push_back({a,b});
		memset(res,-1,sizeof(res));
		for(int j=0; j<n; j++)
		{
			cin>>x>>y;
			vec.push_back({x,y});
		}
		for(int i=0; i<=n; i++)
		{
			for(int j=0; j<=n; j++)
			{
				int dis=abs(vec[i].first- vec[j].first)+ abs(vec[i].second- vec[j].second);
				mat[i].push_back({dis, j});
			}
		}
		cout<<"The shortest path has length "<<f(0,1)<<endl;
	}
}