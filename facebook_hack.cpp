#include<bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	string cad;
	for(int i=1; i<=cases; i++)
	{
		int beta=0,puntos=0;
		cin>>cad;
		for(int j=0; j<cad.size(); j++)
		{
			if(cad[j]=='B')
				beta++;
			if(cad[j]=='.')
				puntos++;
		}
		if((beta>=puntos and puntos!=0) or (beta>=2 and puntos>=1))
			cout<<"Case #"<<i<<": Y\n";
		else
			cout<<"Case #"<<i<<": N\n";

	}
}