#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	cin>>cad;
	int con=0;
	char ban='w';
	bool p=0;
	for(int i=0; i<cad.size(); i++)
	{
		if(ban==cad[i])
		{
			con++;
		}
		else
		{
			ban=cad[i];
			con=1;
		}
		if(con>=7)
			p=1;
	}
	if(p)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}