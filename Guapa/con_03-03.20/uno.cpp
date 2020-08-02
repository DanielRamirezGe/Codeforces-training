#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,n,t,aux;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>n>>t;
		vector <int> vec;
		int sum=0;
		for(int i=0; i<n; i++)
		{
			cin>>aux;
			vec.push_back(aux);
			if(i>=1)
				sum+=aux;
		}
		if(sum+vec[0]>=t)
			cout<<t<<endl;
		else
			cout<<sum+vec[0]<<endl;

	}
}