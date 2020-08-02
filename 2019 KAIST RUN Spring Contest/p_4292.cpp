#include <bits/stdc++.h>
using namespace std;
#define men 1000005
bool fun(pair<int,int> a, pair<int,int> b)
{
	if(a.first>b.first)
		return true;
	if(a.first<b.first)
		return false;
	if(a.second<b.second)
		return true;
	return false;
}
int main()
{
	int a,b,aux, p[men];
	scanf("%d %d",&a,&b);
	vector<pair<int,int>> vec;
	for(int i=0; i<a; i++)
	{
		scanf("%d",&aux);
		p[i]=aux;
	}
	sort(p, p+a);
	int con=0, uno,dos;
	for(int i=0; i<b; i++)
	{
		con=0;
		scanf("%d",&aux);
		uno=0,dos=a-1;
		for(int j=0; j<a; j++)
		{
			//cout<<aux-p[j]<<" ";
			auto it=lower_bound(p+j, p+a, aux-p[j]);
			if(*it==aux-p[j] and p[j]!=aux-p[j])
				con++;
		}
		vec.push_back({con,aux});
	}
	sort(vec.begin(), vec.end(), fun);
	for(int i=0; i<vec.size(); i++)
		printf("%d %d\n",vec[i].second,vec[i].first);
}