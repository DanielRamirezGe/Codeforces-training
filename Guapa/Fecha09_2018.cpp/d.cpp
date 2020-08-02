#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
	long long n, a, total=1, num=0;
	bool ban=0;
	cin>>n;
	for(int i=2; i<n+2; i++)
	{

		if(!ban)
		{	
			cin>>a;
			if(total*2>= mod)
				num++;
			total=(total*2)%mod;
			while(a>total and num )
			{
				a-=mod;
				num--;
			}
			
			//cout<<"\t"<<total<<endl;
			total-=a;
			if(total<0)
			{
				/*if(num)
				{
					cout<<"\t"<<i<<"\t"<<total<<endl;
					total=mod+total; 
					num--;
				}
				else*/
					ban=1;
			}
			
		}
	}
	if(ban)
		cout<<"error"<<endl;
	else
		cout<<total<<endl;
}