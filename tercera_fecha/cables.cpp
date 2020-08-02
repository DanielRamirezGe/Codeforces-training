#include <iostream>
#include <vector>
using namespace std;
#define maxi_tam 10009

int vec[maxi_tam];
int cases, num, tot, aux;
int main()
{

	scanf("%d",&cases);
	for(int i=0; i<cases; i++)
	{
		int m=0;
		
		scanf("%d %d",&num,&tot);
		for(int j=0; j<num; j++)
		{
			scanf("%d",&vec[j]);
			if(m<vec[j])
				m=vec[j];
		}
		
		int l=1, r=m+1, mit=l+(r-l)/2;
		while(l<r)
		{
			int con=0;
			for(int i=0; i<num; i++)
				con+=vec[i]/mit;
			if(con>=tot)
				l=mit;
			else
				r=mit-1;
			mit=l+(r-l)/2;
		}	
		printf("%d\n",mit );
	}
	return 0;
}

