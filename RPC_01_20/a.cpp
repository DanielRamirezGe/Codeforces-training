#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,aux;
	cin>>a>>b;
	vector <int >vec;
	int tot=0;
	for(int i=0; i<a; i++)
	{
		cin>>aux;
		vec.push_back(aux);
		tot+=aux;
	}
	for(int i=0; i<a; i++)
	{
		cout<<(b/tot)*vec[i]<<endl;
	}
}