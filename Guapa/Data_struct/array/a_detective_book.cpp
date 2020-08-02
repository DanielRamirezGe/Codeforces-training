#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cuantos,a, contado=0,max;
	cin>>cuantos;
	bool ban=0;
	for(int i=1; i<=cuantos;i++)
	{
		cin>>a;
		if(ban==0)
		{
			ban=1;
			max=a;
		}
		else
			if(max<a)
				max=a;
		if(max<=i)
		{
			ban=0;
			contado++;	
		}

	}
	cout<<contado<<endl;
}