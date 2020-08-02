#include <bits/stdc++.h>
using namespace std;
#define und -1
int node,edges;
int dfs_counter;
vector <int> dfs_num, dfs_low, dfs_parent, articulation;

void arti(int u)
{
	dfs_low[u]=dfs_num[u]=dfs_counter++;
}


int main()
{
	int q;
	cin>>node>>edges;
	for(int i=0; i<edges; i++)
	{
		cin>>a>>b;
		mat[a].push_back(b);
		mat[b].push_back(a);
	}
	dfs_counter=0;
	dfs_num.assing(node, und);
	dfs_low.assing(node, 0);
	dfs_parent.assing(node, 0);
	articulation.assing(node, 0);









	cin>>q;
	for(int i=0; i<q; i++)
	{
		cin>>a>>b;
	}

}