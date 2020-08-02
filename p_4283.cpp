#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases, list, num, query, option;
	scanf("%d",&cases);

	multiset<int> mapa;
	for(int i=0; i<cases; i++)
	{
		mapa.clear();
		scanf("%d",&list);
		for(int j=0; j<list; j++)
		{
			scanf("%d",&num);
			mapa.insert(num);
		}
		scanf("%d", &query);
		for(int j=0; j<query; j++)
		{
			scanf("%d %d",&option,&num);
			if(option==1)
			{
				
				auto it=mapa.lower_bound(num);
				if(it==mapa.begin())
					printf("-1 ");
				else
				{
					it--;
					printf("%d ",*it);
				}
				auto dos=mapa.upper_bound(num);
				if(dos==mapa.end())
					printf("100001\n");
				else
					printf("%d\n",*dos);
				
				
			}
			if(option==3)
			{
				auto it=mapa.find(num);
				if(it!=mapa.end())
					mapa.erase(it);
			}
			if(option==2)
				mapa.insert(num);
		}
	}
}