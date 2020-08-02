#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<char,int> mapa;
	string cad;
	cin>>cad;
	for(int i=0; i<cad.size(); i++)
	{
		mapa[cad[i]]++;
	}
	bool ban_1=0;
	bool ban_2=0;
	for(auto a: mapa)
	{
		if(a.second%2==0)
			ban_1=1;
		else
			ban_2=1;
	}
	if(ban_2 and ban_1)
		cout<<2<<endl;
	else
		if(ban_2)
			cout<<1<<endl;
		else
			cout<<0<<endl;
}