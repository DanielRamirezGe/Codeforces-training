#include <bits/stdc++.h>
using namespace std;
int num;
int n,aux;
vector<int> vec;
bool ban=0; 

void f(int suma, int pos, int tot)
{
	if(tot==1)
	{
		for(int i=pos; pos<n; pos++)
		{
			if(suma+vec[i]== num)
				ban=1;

		}
		return;
	}
	for(int i=pos; i<n; i++)
		f(suma+vec[i], i+1, tot-1);

	return;
}
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>num>>n;
		vec.clear();
		for(int i=0; i<n; i++)
		{
			cin>>aux;
			vec.push_back(aux);
		}
		ban=0;
		for(int i=1; i<=n; i++)
		{
			f(0, 0, i);
			if(ban)
				break;

		}
		if(ban or num==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}