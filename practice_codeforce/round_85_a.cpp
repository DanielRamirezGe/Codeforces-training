#include <bits/stdc++.h>
using namespace std;
int main()
{
	string uno,dos;
	cin>>uno>>dos;
	for(int i=0; i<dos.size(); i++)
	{
		uno[i]=tolower(uno[i]);
		dos[i]=tolower(dos[i]);
	}
	for(int i=0; i<dos.size(); i++)
	{
		if(uno[i]!=dos[i])
		{
			if(uno[i]<dos[i])
				cout<<-1<<endl;
			else
				cout<<1<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}