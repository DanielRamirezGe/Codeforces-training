#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	string cad;
	int con=0;
	for(int i=0; i<cases; i++)
	{
		cin>>cad;
		if(cad[0]=='+' or cad[1]=='+' or cad[2]=='+')
			con++;
		else
			con--;
	}
	cout<<con<<endl;
}