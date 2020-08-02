#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,a,b;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>a>>b;
		if(a<b)
		{
			int d=b-a;
			if(d%2==1)
				cout<<1<<endl;
			else
				cout<<2<<endl;
		}
		else
			if(a>b)
			{
				int d=a-b;
			if(d%2==0)
				cout<<1<<endl;
			else
				cout<<2<<endl;

			}
			else
				cout<<0<<endl;
	}

}