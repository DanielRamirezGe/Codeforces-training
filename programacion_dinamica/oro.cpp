#include <bits/stdc++.h>
using namespace std;
#define maxi 25
#define inf 99999999
#define maxi_bit 70000
vector <pair<int,int>> vec;
pair <int,int> origen, gold;
int res[maxi][maxi][maxi_bit];
int  completo;
void imp(int bit)
{
	vector<int> v;
	for(int i=0; i<5; i++)
		if( bit & 1<<i)
			v.push_back(1);
		else
			v.push_back(0);
	for(int i=4; i>=0; i--)
		cout<<v[i];
	cout<<endl;
}
int f(int x, int y, int bit)
{
	//cout<<x<<" "<<y<<" ";
	//imp(bit);


	if(bit==completo)
	{

		int dis=abs(x-origen.first)+abs(y-origen.second);
		//cout<<"resgreso: "<<dis<<endl;
		return dis;
	}
	if(res[x][y][bit]!=-1)
	{
		//cout<<"regreso: "<<res[x][y][bit]<<endl;
		return res[x][y][bit];
	}

	int mini= inf;
	for(int i=0; i<vec.size(); i++)
	{
		if( !(bit & 1<<(i)) )
		{
			
			bit|=(1<<i);
			int resul=f(vec[i].first, vec[i].second,bit);
			//cout<<x<<" "<<y<<" "<<i<<" "<<resul<<" "<<dis<<endl;
			int dis=abs(x-vec[i].first)+abs(y-vec[i].second);
			//cout<<"dis: "<<dis<<" r: "<<resul<<" ---  "<<x<<" "<<y<<" "<<vec[i].first<<" "<<vec[i].second<<endl;
			resul+=dis;
				
			bit-=(1<<i);
			
			if(resul<mini)
				mini=resul;
			
		}
	}
	//cout<<"regreso: "<<mini<<" "<<x<<" "<<y<<endl;
	return res[x][y][bit]=mini;
}
int main()
{
	int cases,n,m;
	cin>>cases;
	char aux;
	for(int i=0; i<cases; i++)
	{
		cin>>n>>m;
		vec.clear();
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				cin>>aux;
				if(aux=='x')
				{
					origen.first=i;
					origen.second=j;
				}
				if(aux=='g')
				{
					gold.first=i;
					gold.second=j;
					vec.push_back(gold);
				}

			}
		}
		completo=(1<<vec.size())-1;
		//cout<<" completo: "<<completo<<endl;
		memset(res,-1,sizeof(res));
		cout<<"Case "<<i+1<<": "<<f(origen.first, origen.second, 0)<<endl;

	}
}