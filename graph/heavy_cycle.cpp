#include <bits/stdc++.h>
using namespace std;
#define maxi 1009
vector<pair<int,int>> mat[maxi];
int main()
{
	int n,m,a,b,z;
	while(cin>>n>>m and (n!=0 or m!=0) )
	{
		for(int i=0; i<maxi; i++)
			mat[i].clear();
		for(int i=0; i<m; i++)
		{
			cin>>a>>b>>z;
			mat[a].push_back({z,b});
			mat[b].push_back({z,a});
		}
		priority_queue< pair<int,int>, vector<pair<int,int> >, greater< pair<int,int> > > pq;
		
		map <int,int >mapa, aris,nuevo;
		for(int i=0; i<n; i++)
		{
			if(mapa[i]==0)
			{	
				pq.push({0,i });
				while(!pq.empty())
				{
					auto nod=pq.top();
					pq.pop();
					if(mapa[nod.second]==0)
					{
						mapa[nod.second]++;
						aris[nod.first]++;
						for(auto a: mat[nod.second])
							if(mapa[a.second]==0)
								pq.push(a);
					}

				}
			}
		}
		
		map< int,int> todos;
		for(int i=0; i<=n; i++)
			for(auto x: mat[i])
				todos[x.first]++;

		for(auto &x: todos)
			x.second/=2;

		vector<int> imp;
		
		for(auto x: todos)
		{
			int arista=x.first;
			int tam=x.second;
			int menos=aris[arista];
			for(int i=0; i<tam-menos; i++)
				imp.push_back(arista);

		}

		if(imp.size()==0)
			cout<<"forest"<<endl;
		else
		{
			for(int i=0; i<imp.size(); i++)
			{
				cout<<imp[i];
				if(i!=imp.size()-1)
					cout<<" ";
			}
			cout<<endl;
		}
	}
}