#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad, dos;
	getline(cin,cad);
	getline(cin,dos);
	int con=0;
	for(int i=0; i<=cad.size()-dos.size(); i++)
	{
		bool ban=0;
		for(int j=0; j<dos.size(); j++)
		{
			if(cad[i+j]==dos[j])
			{
				ban=1;
				break;
			}
		}
		if(!ban)
			con++;
	}
	cout<<con<<endl;
}