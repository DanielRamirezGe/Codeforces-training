#include <bits/stdc++.h>
using namespace std;
#define maxi 200009
vector <int> mat[maxi];
int dis[maxi];
int main()
{
	int n,s,t, aux, a, b;
	cin>>n>>s>>t;
	vector <int> vec;
	for(int i=0; i<t; i++)
	{
		cin>>aux;
		vec.push_back(aux);
	}
	for(int i=0; i<s; i++)
	{
		cin>>a>>b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	queue <int > cola; 	
	memset(dis, -1, sizeof(dis));
	cola.push(1);
	dis[1]=0;
	while(!cola.empty())
	{
		//cout<<cola.front()<<" :"<<endl;
		for(auto x: mat[cola.front()])
		{
			//cout<<x<<" ";
			if(dis[x]==-1)
			{
				cola.push(x);
				dis[x]=dis[cola.front()]+1;
			}
		}
		//cout<<endl; 	
		cola.pop();
	}
	
	vector < pair<int,int> > ord;
	for(int i=0; i<vec.size(); i++)
	{
	//	cout<<vec[i]<<endl;
		ord.push_back({dis[vec[i]], vec[i]});
	}

	sort(ord.begin(), ord.end());
	int di=9999999;
	int uno,dos;

	// for(auto x: ord)
	// 	cout<<x.first<<" "<<x.second<<endl;
	for(int i=1; i<ord.size(); i++)
	{
		//cout<<ord[i].first<<" "<<ord[i].second<<endl;
		
			if(abs(ord[i].first-ord[i-1].first) < di)
			{
				uno=ord[i].second;
				dos=ord[i-1].second;
				di=abs(ord[i].first-ord[i-1].first);
			}

	}
	mat[uno].push_back(dos);
	mat[dos].push_back(uno);
	memset(dis, -1, sizeof(dis));
	cola.push(1);
	dis[1]=0;
	while(!cola.empty())
	{
		for(auto x: mat[cola.front()])
		{
			if(dis[x]==-1)
			{
				cola.push(x);
				dis[x]=dis[cola.front()]+1;
			}
		}
		cola.pop();
	}
	cout<<dis[n]<<endl;

}