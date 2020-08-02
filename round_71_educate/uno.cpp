#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int tot=0;
		int sum=0;
		int b, a, c, uno,dos;
		cin>>b>>a>>c>>uno>>dos;
		if(uno>dos)
		{
			
			if(a*2>b)
			{
				sum+=(b/2)*uno;
				b=0;
			}
			else
			{
				sum +=uno*a;
				b-=a*2;
			}
			if(b>0)
			{
				if(c*2>b)
					sum+=(b/2)*dos;
				else
					sum+=c*dos;

			}
		}
		else
		{
			if(c*2>b)
			{
				sum+=(b/2)*dos;
				b=0;
			}
			else
			{
				sum +=dos*c;
				b-=c*2;
			}
			if(b>0)
			{
				if(a*2>b)
					sum+=(b/2)*uno;
				else
					sum+=a*uno;
			}
		}
		cout<<sum<<endl;
	}
}