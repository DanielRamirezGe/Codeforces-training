#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,aux,n;
	cin>>cases;
	vector <int> vec;
	long long suma=0,busca;
	for(int i=0; i<cases; i++)
	{
		suma=0;
		cin>>n;
		vec.clear();
		for(int j=0; j<n; j++)
		{
			cin>>aux;
			vec.push_back(aux);
			suma+=aux;
		}
		busca=suma/n;
		if(suma%n==0)
		{
			bool ban=1;
			for(int i=0; i<n and ban; i++)
			{
				if(vec[i]==busca)
				{
					ban=0;
					cout<<i+1<<endl;
					break;
				}
			}
			if(ban)
				cout<<"Impossible\n";
		}
		else
			cout<<"Impossible\n";
		
	}
}