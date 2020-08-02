#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	cin>>cad;
	for(int i=0; i<cad.size(); i++){
		if(cad[i]=='o' or cad[i]=='O')
			cout<<0;
		else if( cad[i]=='i' or cad[i]=='I' )
			cout<<1;
		else if( cad[i]=='z' or cad[i]=='Z' )
			cout<<2;
		else if( cad[i]=='E' or cad[i]=='e' )
			cout<<3;
		else if( cad[i]=='A' or cad[i]=='a' )
			cout<<4;
		else if( cad[i]=='s' or cad[i]=='S' )
			cout<<5;
		else if( cad[i]=='g' or cad[i]=='G' )
			cout<<6;
		else if( cad[i]=='t' or cad[i]=='T' )
			cout<<7;
		else if( cad[i]=='B' or cad[i]=='b' )
			cout<<8;
		else
			cout<<cad[i];

	}
	cout<<endl;
}