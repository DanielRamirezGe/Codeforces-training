#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,n,d;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		cin>>n>>d;
		int aux;
		vector<int> vec;
		int maxi=0;
		for(int i=0; i<n; i++)
		{
			cin>>aux;
			vec.push_back(aux);
			if(maxi<aux)
				maxi=aux;
		}
		bool ban=0;
		for(int i=0; i<n; i++)
			if(vec[i]==d)
			{
				ban=1;
				break;
			}
		if(ban)n
			cout<<1<<endl;
		else
		{
			long long tot=ceil((double)d/(double)maxi);
			if(tot==1)
				tot++;
			cout<<tot<<endl;
		}
	}
}