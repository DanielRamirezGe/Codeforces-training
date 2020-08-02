#include <bits/stdc++.h>
using namespace std;
#define maximo 1000009
typedef pair<int, int> ii;
int padre[maximo];
ii save[maximo];
int main()
{
	int operation;
	int id, option, x;
	ii aux;
	scanf("%d",&operation);
	for(int i=1; i<=operation; i++)
	{
		scanf("%d %d",&id,&option);
		if(option==0)
		{
			scanf("%d",&x);
			aux=save[id];
			int tam=aux.first;
			save[i].first=tam+1;
			save[i].second=x;
			padre[i]=id;
			printf("%d\n",tam+1);
		}
		else
		{
			if(id!=0)
			{
				

				int tama=save[id].first;
				//cout<<id<<" -- "<<option<<"  "<<tama<<endl;
				if(tama==0)
				{
					save[i].first=0;
					save[i].second=0;
					printf("-1\n");
				}
				else
				{
					tama--;
					printf("%d\n",save[id].second);
					int valor=save[padre[id]].second;
					save[i].first=tama;
					save[i].second=valor;


				}

				int pad=padre[id];
				if(pad!=0)
				{
					pad=padre[pad];
					padre[i]=pad;
				}
				else
					padre[i]=0;

			}
			else
			{
				padre[i]=0;
				save[i].first=0;
				save[i].second=0;
				printf("-1\n");
			}
		}
	}
}