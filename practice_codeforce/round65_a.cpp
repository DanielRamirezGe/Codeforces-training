#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>cad;
		if(cad.size()>10)
		{
			int num=cad.size()-2;
			cout<<cad[0]<<num<<cad[cad.size()-1]<<endl;
		}
		else
			cout<<cad<<endl;
	}
}