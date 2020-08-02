#include <bits/stdc++.h>
using namespace std;
#define inf 99999999
int main()
{
	int cases,lines,S,f,t;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int may=-inf;
		cin>>lines>>S;
		for(int i=0; i<lines; i++)
		{
			cin>>f>>t;
			if(t<=S and f>may)
				may=f;
			else
				if(t>S and (f-(t-S))>may)
					may=(f-(t-S));
		}
		cout<<"Case #"<<i+1<<": "<<may<<endl;
	}
}