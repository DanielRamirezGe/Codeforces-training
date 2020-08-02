#include <bits/stdc++.h>
using namespace std;
#define maxi 50005
vector<int> mat[maxi];
bool visi[maxi];
int level[maxi];
int segmet[8*maxi];
vector<int> eulerian;
int primera[maxi];
int distacia[2][maxi];
int padre[maxi];
void dfs(int nodo, int prof)
{
	visi[nodo]=true;
	primera[nodo]=eulerian.size();
	eulerian.push_back(nodo),
	level[nodo]=prof;
	for(int i=0; i<mat[nodo].size(); i++)
	{
		int a=mat[nodo][i];
		if(!visi[a])
		{
			padre[a]=nodo;
			dfs(a, prof+1);
			eulerian.push_back(nodo);
		}
	}
}

void buil(int i, int j, int p)
{
	if(i==j)
	{
		segmet[p]=eulerian[i];
		return;
	}
	buil(i, (i+j)/2, p<<1);
	buil(((i+j)/2)+1, j, (p<<1)+1);
	segmet[p]=(level[segmet[p<<1]]<level[segmet[(p<<1)+1]]? segmet[p<<1]:segmet[(p<<1)+1]);
}
void bfs(int nodo,int i)
{
	queue<int> q;
	q.push(nodo);
	distacia[i][nodo]=0;
	while(!q.empty())
	{
		int u=q.front();
		//cout<<"     "<<u<<endl;
		q.pop();
		for(auto a: mat[u])
		{
			if(distacia[i][a]==-1)
			{
				distacia[i][a]=distacia[i][u]+1;
				q.push(a);
			}
		}
	}
}
int consultar(int i, int j, int a,int b, int p)
{
	//cout<<i<<" "<<j<<" "<<a<<" "<<b<<end
	if(i>b or j<a)
		return -1;
	if(i>=a and j<=b)
		return segmet[p];
	int l=consultar(i,(i+j)/2, a, b, p<<1);
	int r=consultar(((i+j)/2)+1, j, a, b, (p<<1)+1);
	if(l==-1)
		return r;
	if(r==-1)
		return l;
	return (level[l]<level[r]? l:r);
}
int main()
{
	int tot,a,b, query,uno,dos,tres;
	while(scanf("%d",&tot) and tot!=0)
	{
		memset(distacia, -1, sizeof(distacia));
		for(int i=0; i<maxi; i++)
			mat[i].clear();
		eulerian.clear();
		memset(visi, 0, sizeof(visi));

		for(int i=1; i<tot; i++)
		{
			scanf("%d %d",&a,&b);
			mat[a].push_back(b);
			mat[b].push_back(a);
		}
		dfs(1, 0);
		buil(0, eulerian.size()-1, 1);
		scanf("%d",&query);
		for(int i=0; i<query; i++)
		{
			memset(distacia, -1, sizeof(distacia));

			scanf("%d %d",&a,&b);
			//cout<<a<<" "<<b<<endl;
			uno=primera[a];
			dos=primera[b];
			if(uno>dos)
			{
				tres=uno;
				uno=dos;
				dos=tres;
			}

			int LCA=consultar(0, eulerian.size()-1,uno, dos, 1);
			//cout<<level[a]<<"  "<<level[b]<<"  "<<level[LCA]<<endl;
			int t=abs(level[a]-level[LCA])+abs(level[b]-level[LCA])+1;
			//bfs(a,0);
			//bfs(b,1);
			//t=distacia[0][b]+1;
			if(t&1)
			{
				int n;
				int mitad=t/2;
				int x=abs(level[a]-level[LCA]),y=abs(level[b]-level[LCA]);
				if(x > y)
				{
					n=a;
					for(int i=0; i<mitad; i++)
						n=padre[n];
				}
				else
				{
					n=b;
					for(int i=0; i<mitad; i++)
						n=padre[n];
				}
				cout<<"The fleas meet at "<<n<<".\n";
			}
			else
			{
				int mitad=t/2,n;
				int x=abs(level[a]-level[LCA]),y=abs(level[b]-level[LCA]);
				if(x>y)
				{
					n=a;
					for(int i=0; i<mitad-1; i++)
						n=padre[n];
					uno=n;
					dos=padre[n];
				}
				else
				{
					n=b;
					for(int i=0; i<mitad-1; i++)
						n=padre[n];
					uno=n;
					dos=padre[n];

				}
				//cout<<uno<<" "<<dos<<endl;
				cout<<"The fleas jump forever between "<<(uno<dos? uno:dos)<<" and "<<(dos<uno? uno: dos)<<".\n";
			}


		}

	}
}