#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num;
	cout<<"PERFECTION OUTPUT\n";
	while(cin>>num and num!=0)
	{
		long long tot=0;
		for(int i=1; i<num; i++)
		{
			if(num%i==0)
				tot+=i;
		}
		if(tot>num)
			printf("%5d  ABUNDANT\n",num);
		else
			if(tot<num)
				printf("%5d  DEFICIENT\n",num);
			else
				printf("%5d  PERFECT\n",num);

	}
	cout<<"END OF OUTPUT\n";
}