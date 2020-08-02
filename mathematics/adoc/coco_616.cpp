#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num;
	while(cin>>num and num>=0)
	{
		int max=0;
		for(int i=2; i<50; i++)
		{
			bool ban=1;
			int cop=num,parte;
			if(num==0)
				break;
			for(int j=1; j<=i; j++)
			{
				parte=(cop/i);
				if(parte>0)
				{
					if(cop%parte>1 or cop%parte==0)
					{
						ban=0;
						break;
					}
				}
				else
				{
					break;
						ban=0;
				}
				cop=cop-parte-1;
				
				if(cop==0 )
				{
					ban=0;
					break;
				}
				if(parte<i)
				{
					ban=0;
					break;
				}
			}
			if(cop%i!=0)
				ban=0;
			if(ban)
				max=i;

		}
		if(num==3)
			cout<<"3 coconuts, 2 people and 1 monkey\n";
		else
		if(max==0)
			cout<<num<<" coconuts, no solution\n";
		else
			cout<<num<<" coconuts, "<<max<<" people and 1 monkey\n";

	}
}