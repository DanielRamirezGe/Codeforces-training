#include <bits/stdc++.h>
using namespace std;
#define maxi 100000
vector <int> vec;
pair<int,int> res[maxi];
void f()
{
	for(int i=0; i<vec.size(); i++)
	{
		int m=0;
		int pad=-1;
		for(int j=0; j<i; j++)
		{		
			if(res[j].first > m and vec[j]<vec[i])
			{
				m=res[j].first;
				pad=j;
			}
			else
				if(m!=0)
					if(res[j].first == m and vec[pad]>vec[j])
						pad=j;
		}
		
		res[i].first=m+1;
		res[i].second=pad;
	}
}
int main()
{
	int n;
	while(scanf("%d",&n)==1)
		vec.push_back(n);
	f();
	int maximo=0;
	int emp=0;
	for(int i=0; i<vec.size(); i++)
		if(maximo<= res[i].first)
		{
			maximo=res[i].first;
			emp=i;
		}

	cout<<maximo<<endl<<"-"<<endl;
	vector<int> rep;
	while(emp!=-1)
	{
		rep.push_back(vec[emp]);
		emp=res[emp].second;
	}
	for(int i=rep.size()-1; i>=0; i--)
		cout<<rep[i]<<endl;
}