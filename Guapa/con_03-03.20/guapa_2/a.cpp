#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,s;
	cin>>n>>s;
	char mat[n][n];
	int acc[n+9][n+9];
	memset(acc, 0, sizeof(acc));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{

			cin>>mat[i][j];
			if(mat[i][j]=='D')
				acc[i][j]=1;
		}
	
	for(int i=0; i<n; i++)
		for(int j=1; j<n; j++)
			acc[i][j]+=acc[i][j-1];
	
	map<int,int> mapa;
	// for(int i=0; i<n; i++, cout<<endl)
	// 	for(int j=0; j<n; j++)
	// 		cout<<acc[i][j]<<" ";

	for(int j=0; j+s-1<n; j++)
	{
		for(int i=s-1; i<n; i++)
		{
			int tot=0;
			for(int h=0; h<s; h++)
			{

				tot+=acc[j+h][i];
				if(i-s>=0)
					tot-=acc[j+h][i-s];
				//cout<<j+h<<" "<<i<<": "<<tot<<endl;

			}
			//cout<<tot<<":  "<<j<<" "<<i<<endl;
			mapa[tot]++;
		}
	}
	vector < pair<int,int> > vec;
	for(auto x: mapa)
	{
		vec.push_back({x.first, x.second});
	}
	sort(vec.begin(), vec.end());
	for(auto x: vec)
		cout<<x.first<<" "<<x.second<<endl;


}