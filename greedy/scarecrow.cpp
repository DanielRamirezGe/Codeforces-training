#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int p;
		cin>>p;
		string cad;
		cin>>cad;
		int con=0;
		for(int i=0; i<cad.size(); i++)
		{
			if(cad[i]=='.')
			{
				con++;
				i+=2;
			}
		}
		cout<<"Case "<<i+1<<": "<<con<<endl;
	}
}