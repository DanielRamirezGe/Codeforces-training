	#include <bits/stdc++.h>
	using namespace std;
	int main()
	{
		int a,b;
		cin>>a>>b;
		if(a>b )
		{
			if((360-a)+b < abs(a-b))
				cout<<(360-a)+b<<endl;
			else
				cout<<-(a-b)<<endl;
		}
		else
		{
			int c=a;
			a=b;
			b=c;
			if((360-a)+b < abs(a-b))
				cout<<-((360-a)+b)<<endl;
			else
				cout<<(a-b)<<endl;
		}
	}