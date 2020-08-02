#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,n,aux;
	cin>>cases;

	for(int i=0; i<cases; i++)
	{
		vector<int> vec;
		cin>>n;
		for(int j=0; j<n; j++)
		{
			cin>>aux;
			vec.push_back(aux);
		}
		sort(vec.begin(), vec.end());
		cout<<"Case "<<i+1<<": "<<vec[n/2]<<endl;
	}
}
