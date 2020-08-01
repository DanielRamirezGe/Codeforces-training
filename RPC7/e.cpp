#include <bits/stdc++.h>
using namespace std;
#define mx 130
bool mat [mx][mx];
int dis  [mx][mx];
int arr  [mx];
int main()
{
	int cases;
	cin>>cases; 
	for(int i=0; i<cases; i++){
		int n;
		cin>>n;
		memset(mat, 0, sizeof(mat));
		memset( dis, -1, sizeof(dis));
		for(int i=0; i<n; i++){
			int aux;
			cin>>aux;
			arr[i+1]=aux+1;
			for(int j=1; j<=aux+1; j++)
				mat[i+1][j]=1;

		}

		int a,b,c,d;
		cin>>a>>b>>c>>d;
		queue <pair <int,int>> cola;
		
		cola.push({a,b+1});
		dis[a][b+1]=0;
		while(!cola.empty())
		{
			pair<int,int> p = cola.front();
			//cout<<p.first<<" "<<p.second<<" "<<dis[ p.first ][p.second]<<endl;
			cola.pop();
			if(mat[ p.first-1 ][p.second] and dis[ p.first-1 ][p.second]==-1){
				dis[ p.first-1 ][p.second] = dis[ p.first ][p.second] +1;
				cola.push({p.first-1 ,p.second});
			}
			if(mat[ p.first ][p.second-1] and dis[ p.first ][p.second-1]==-1){
				dis[ p.first ][p.second-1] = dis[ p.first ][p.second] +1;
				cola.push({p.first ,p.second-1});
			}
			if(mat[ p.first ][p.second+1] and dis[ p.first ][p.second+1]==-1){
				dis[ p.first ][p.second+1] = dis[ p.first ][p.second] +1;
				cola.push({p.first ,p.second+1});
			}
			if(mat[ p.first +1][p.second] and dis[ p.first +1][p.second]==-1){
				dis[ p.first +1][p.second] = dis[ p.first ][p.second] +1;
				cola.push({p.first +1,p.second});
			}
			if( p.second == 1 and p.first!=1){
				if( dis [p.first-1 ][arr[p.first-1]] == -1){
					dis [p.first-1 ][arr[p.first-1]] = dis[ p.first ][p.second] +1;
					cola.push({p.first-1,arr[p.first-1]});
				}

			}
			if( p.second+1 > arr[p.first]  and p.first!=n ){
				if( dis[p.first+1][1] ==-1 ){
					dis[p.first+1][1] = dis[ p.first ][p.second] +1;
					cola.push({p.first+1,1});
				}
			}
			if( arr[ p.first-1 ] < p.second  and p.first!=1){
				if( dis[ p.first-1 ][ arr[ p.first-1 ] ] == -1){
					dis[ p.first-1 ][ arr[ p.first-1 ] ] = dis[ p.first ][p.second] +1;
					cola.push({p.first-1, arr[ p.first-1 ] });
				}
			}
			if( arr[ p.first+1 ] < p.second and p.first!=n ){
				if( dis[ p.first+1 ][ arr[ p.first+1 ] ] == -1){
					dis[ p.first+1 ][ arr[ p.first+1 ] ] = dis[ p.first ][p.second] +1;
					cola.push({p.first+1, arr[ p.first+1 ] });
				}
			}
		}
		cout<<dis[c][d+1]<<endl;
	}
}