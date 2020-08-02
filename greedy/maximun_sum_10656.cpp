#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,aux;
	vector<int> vec;
	while(cin>>n and n!=0)
	{
		vec.clear();
		for(int i=0; i<n; i++)
		{
			cin>>aux;
			if(aux!=0)
				vec.push_back(aux);
		}
		for(int i=0; i<vec.size(); i++)
		{
			cout<<vec[i];
			if(i!=vec.size()-1)
				cout<<" ";
			else
				cout<<endl;
		}
		if(vec.size()==0)
			cout<<0<<endl;
	}
}