#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		int n;
		string cad;
		cin>>n>>cad;
		long long a=0,b=0;
		for(int i=0; i<cad.size(); i++)
			if(cad[i]=='A') a++;
			else b++;
		cout<<"Case #"<<i+1<<": "<<(abs(a-b)==1 ? 'Y' : 'N')<<endl;
	}
}