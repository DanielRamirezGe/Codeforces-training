#include <bits/stdc++.h>
using namespace std;
#define max_money 20003
#define max_tomado 109
#define inf 999999999
int money,total;
int res[max_money][max_tomado];
vector<pair <int,int> > arr;
int f( int tomado, int pos )
{
	if(pos==total)
	{
		if(tomado<=money)
			return 0;
		else
			if(tomado>2000 and money+200>=tomado)
				return 0;
			else
				return -inf;
	}
	if(money+200 < tomado)
		return -inf;
	if(res[tomado][pos]!=-1)
		return res[tomado][pos];
	int a=f(tomado+arr[pos].first, pos+1)+ arr[pos].second;
	int b=f(tomado, pos+1);
	return res[tomado][pos]=max(a,b);

}
int main()
{
	int price,eny;
	while(cin>>money>>total)
	{
		arr.clear();
		memset(res,-1,sizeof(res));
		for(int i=0; i<total; i++)
		{

			cin>>price>>eny;
			arr.push_back({price,eny});
			
		}
		cout<<f(0,0)<<endl;
	}
}