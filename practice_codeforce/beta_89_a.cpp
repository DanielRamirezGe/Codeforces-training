#include <bits/stdc++.h>
using namespace std;
int main()
{
	string uno="", dos="";
	cin>>uno;

	for(int i=0; i<uno.size(); i++)
		uno[i]=tolower(uno[i]);
	for(int i=0; i<uno.size(); i++)
	{
		if(uno[i]!='a' and uno[i]!='e' and uno[i]!='i' and uno[i]!='o' and uno[i]!='u' and uno[i]!='y')
		{
			dos.push_back('.');
			dos.push_back(uno[i]);
		}
	}
	cout<<dos<<endl;
}