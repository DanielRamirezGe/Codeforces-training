#include <bits/stdc++.h>
using namespace std;
#define maxi 1000000
int tree[maxi];
int LSO(int a)
{
	return a&-a;
}
int rqs(int b)
{
	int sum=0;
	for( ; b; b-=LSO(b))
		sum+=tree[b];
	return sum;
}
void act(int k, int v)
{
		for( ; k<maxi; k+=LSO(k))
			tree[k]+=v;
}
int main()
{
	int tam,aux, tope,total=0;
	pair <int,int> pp;	
	priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	while(scanf("%d",&tam)==1 and tam!=0)
	{
		memset(tree, 0, sizeof(tree));
		for(int i=1; i<=tam; i++)
		 		act(i,1);

		for(int i=1; i<=tam; i++)
		{
			scanf("%d",&aux);
			pq.push({aux,i});
		}
		total=0;
		while(!pq.empty())
		{
			pp=pq.top();
			pq.pop();
			tope=rqs(pp.second);
			act(pp.second, -1);
			if(tope>0)
				tope--;
			total+=tope;
		}
		printf("%d\n",total);
	}
}