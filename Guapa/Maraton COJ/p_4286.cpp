#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,aux;
	scanf("%d",&n);
	priority_queue<int> p;
	priority_queue < int, vector<int>, greater<int>> q;
	for(int i=0; i<n; i++)
	{
		scanf("%d",&aux);
		p.push(aux);
		q.push(aux);
		printf("%d\n",p.top()+q.top());
	}
}