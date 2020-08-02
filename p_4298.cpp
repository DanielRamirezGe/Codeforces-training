#include <bits/stdc++.h>
using namespace std;
#define maximo 1001
int main()
{
	int cases,n,m,aux;
	vector<int> vec;
	bool arr[maximo];
	scanf("%d",&cases);
	for(int i=0; i<cases; i++)
	{
		scanf("%d %d",&n,&m);
		memset(arr, 0, sizeof(arr));
		for(int j=0; j<m; j++)
		{
			scanf("%d",&aux);
			//cout<<aux<<endl;
			arr[aux]=1;
		}
		for(int j=1; j<=n; j++)
			if(!arr[j])
				vec.push_back(j);
		for(int j=0; j<vec.size(); j++)
		{
			printf("%d",vec[j]);
			if(j!=vec.size()-1)
				printf(" ");
		}
		vec.clear();
		printf("\n");
	}
}