#include <bits/stdc++.h>
using namespace std;
int main()
{
	int num;
	long long tot=0;
	while(cin>>num)
	{
		while(num>0)
		{
			num/=3;
			num-=2;
			if(num>0)
			tot+=num;
			//cout<<num<<endl;
		}
		//cout<<endl;
		
	}
	cout<<tot<<endl;
}