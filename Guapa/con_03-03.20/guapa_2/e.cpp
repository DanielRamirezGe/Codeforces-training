#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int copia=n;
	string a,b;
	cin>>a>>b;
	int dif=0;
	int equ=0;
	for(int i=0; i<a.size(); i++)
	{
		if(a[i]==b[i])
			equ++;
		else
			dif++;
	}
	int res=0;
	if(n>=equ)
	{
		res+=equ;
		n-=equ;
		dif-=n;
		res+=dif;
		cout<<res<<endl;
	}
	else
	{
		res+=n;
		res+=dif;
		cout<<res<<endl;
	}



}