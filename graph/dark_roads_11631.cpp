#include <bits/stdc++.h>
using namespace std;
#define maxi 200009
vector <pair<int,int>> mat[maxi];
int main()
{
	int m, n, x,y, z;
	while(cin>>m>>n and m!=0 and n!=0)
	{
		for(int i=0; i<maxi; i++)
			mat[i].clear();
		long long suma=0;
		for(int i=0; i<n; i++)
		{
			cin>>x>>y>>z;
			mat[x].push_back({z,y});
			mat[y].push_back({z,x});
			suma+=z;
		
		}
		priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> >  > pq;
		long long tot=0;
		pq.push({0,0});
		map <int, int> mapa;
		while(!pq.empty())
		{
			auto a=pq.top();
			pq.pop();
			if(mapa[a.second]==0)
			{
				//cout<<a.first<<" "<<a.second<<endl;
				mapa[a.second]++;
				tot+=a.first;
				for(auto p: mat[a.second])
					if(!mapa[p.second])
					pq.push(p);
			}
		}
		//cout<<suma<<endl;
		cout<<suma-tot<<endl;
	}
}