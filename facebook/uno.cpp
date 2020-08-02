#include <bits/stdc++.h>
using namespace std;
#define inf 999999999999999
int main()
{
	int cases,a, b, k;
	int n,m;
	cin>>cases;
	long long mat[52][52];
	for(int q=1; q<=cases; q++)
	{
		cin>>n>>m;
		for(int i=0; i<52; i++)
			for(int j=0; j<52; j++)
				mat[i][j]=inf;
		vector<pair<pair<int,int>,int>> vec;
		for(int i=0; i<m; i++)
		{
			cin>>a>>b>>k;
			vec.push_back({{a,b},k});
			mat[a][b]=k;
			mat[b][a]=k;
		}
		for(int k=0; k<=n; k++)
			for(int i=0; i<=n; i++)
				for(int j=0; j<=n; j++)
					mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
		int ban=0;
		for(int i=0; i<vec.size(); i++)
			if(mat[vec[i].first.first][vec[i].first.second]<vec[i].second)
				ban=1;

		cout<<"Case #"<<q<<": ";	
		if(ban)
			cout<<"Implossible"<<endl;
		else
		{
			cout<<m<<endl;
			for(int i=0; i<vec.size(); i++)
				cout<<vec[i].first.first<<" "<<vec[i].first.second<<" "<<vec[i].second<<endl;
		}

	}
}