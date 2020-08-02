#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,n,dos;
	long long aux;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		aux=0;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cin>>dos;
			aux+=dos;
		}
		cout<<aux/3<<endl;
	}

}