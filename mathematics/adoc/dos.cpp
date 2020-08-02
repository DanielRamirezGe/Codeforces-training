#include <bits/stdc++.h>
using namespace std;

int main()
{
	string uno,dos;
	cin>>uno>>dos;
	int con=0;
	for(int i=0; i<uno.size(); i++)
		if(uno[i]==dos[i])
			con++;
	double res=((double)con*100.0)/((double)uno.size()) ;
	cout<<res<<endl;
	if(res>=.99*uno.size())
		cout<<"Long lost brothers D:"<<endl;
	else
		cout<<"Not brothers :("<<endl;
}