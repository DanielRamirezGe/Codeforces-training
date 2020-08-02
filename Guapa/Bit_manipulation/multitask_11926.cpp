#include <bits/stdc++.h>
using namespace std;
#define maxi 1000001
int main()
{
	bitset<maxi> bit;
	bitset<maxi> inicio;
	bitset<maxi> fin;
	int punt,inter,range, aux, a,b;
	while(scanf("%d %d",&punt,&inter) and (punt!=0 or inter!=0))	
	{
		bool ban=1;
		bit.reset();
		inicio.reset();
		fin.reset();
	//	cout<<punt<<" "<<inter<<endl;
		for(int i=0; i<punt ; i++)
		{

			scanf("%d %d",&a,&b);

			if(ban)
			{
				if(bit[a] and !fin[a] )
						ban=0;

				else
					for(int j=a; j<b and ban; j++)
						if(bit[j] and !fin[j])
							ban=0;
						else
							bit[j]=1;

				bit[b]=1;
				inicio[a]=1;
				fin[b]=1;
			}
		}
		for(int i=0; i<inter; i++)
		{
			scanf("%d %d %d",&a,&b,&range);
			if(ban)
			{
				for(int h=0; (h*range)+a<maxi; h++)
				{
					int suma=h*range;
					//cout<<h<<"  "<<a+suma<<endl;
					if(bit[a+suma] and !fin[a+suma] )
					{
						//cout<<"aaaa"<<a<<endl;
						ban=0;
					}
					else
						for(int j=a+suma; j<maxi and j<b+suma and ban; j++)
						{
							//cout<<j<<endl;
							if(bit[j] and !fin[j])
							{
								//cout<<"jjj"<<j<<" "<<a<<endl;
								ban=0;
							}
							else
								bit[j]=1;
						}
					if(b+suma<maxi)
						bit[b+suma]=1;
					inicio[a+suma]=1;
					if(b+suma<maxi)
					fin[b+suma]=1;
				}
			}
		}
		if(ban)
			cout<<"NO CONFLICT"<<endl;
		else
			cout<<"CONFLICT"<<endl;
	//	cout<<punt<<" "<<inter<<endl;
	}
}