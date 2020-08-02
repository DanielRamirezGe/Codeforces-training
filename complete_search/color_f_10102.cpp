#include <bits/stdc++.h>
using namespace std;
vector<	vector<int> > mat;
int M;
int main()
{
	
	int aux;
	vector<int> x;
	while(cin>>M)
	{
		int mat[M][M];
		char aux;	
		for(int i=0; i<M; i++)
			for(int j=0; j<M; j++)
			{
				cin>>aux;
				//cout<<aux;
				mat[i][j]=aux-'0';
			}
			
		int max=0;
		int vis[M][M];
		
		for(int i=0; i<M; i++)
		{
			for(int j=0; j<M; j++)
			{

				if(mat[i][j]==1)
				{
					memset(vis, -1, sizeof(vis));
					vis[i][j]=0;
					queue < pair<int,int> > q;
					q.push({i,j});
					int res;
					while(!q.empty())
					{
						auto p= q.front();
						//cout<<p.first<<" "<<p.second<<endl;
						q.pop();
						if(p.first>0)
						{
							if(vis[p.first-1][p.second]==-1)
							{
								if(mat[p.first-1][p.second]==3)
								{
									res=vis[p.first][p.second]+1;
									break;
								}
								q.push({p.first-1, p.second});
								vis[p.first-1][p.second]=vis[p.first][p.second]+1;
							}
						}
						if(p.second>0)
						{
							if(vis[p.first][p.second-1]==-1)
							{
								if(mat[p.first][p.second-1]==3)
								{
									res=vis[p.first][p.second]+1;
									break;
								}
								q.push({p.first, p.second-1});
								vis[p.first][p.second-1]=vis[p.first][p.second]+1;
							}
						}
						if(p.first<M-1)
						{
							if(vis[p.first+1][p.second]==-1)
							{
								if(mat[p.first+1][p.second]==3)
								{
									res=vis[p.first][p.second]+1;
									break;
								}
								q.push({p.first+1, p.second});
								vis[p.first+1][p.second]=vis[p.first][p.second]+1;
							}
						}
						if(p.second<M-1)
						{
							if(vis[p.first][p.second+1]==-1)
							{
								if(mat[p.first][p.second+1]==3)
								{
									res=vis[p.first][p.second]+1;
									break;
								}
								q.push({p.first, p.second+1});
								vis[p.first][p.second+1]=vis[p.first][p.second]+1;
							}
						}
					}
					//for(int i=0; i<M; i++, cout<<endl)
					//	for(int j=0; j<M; j++)
					//		cout<<vis[i][j]<<" ";
					if(res>max)
						max=res;
				}
			}
		}
		cout<<max<<endl;
	}
}