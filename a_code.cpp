#include <bits/stdc++.h>
using namespace std; 
int main()
{
	int n,a;
	cin>>n;
	vector<int> vec;
	for(int i=0; i<n*2; i++)
	{
		cin>>a;
		vec.push_back(a);
	}
	sort(vec.begin(),vec.end());
	int s_2=0,s_1=0;
	for(int i=0; i<n; i++)
		s_1+=vec[i];
	for(int i=n; i<2*n; i++)
		s_2+=vec[i];
	if(s_1!=s_2)
	{
		for(int i=0; i<2*n; i++)
		{
			cout<<vec[i];
			if(i!=(2*n)-1)
				cout<<" ";
		}
		cout<<endl;
	}
	else
		cout<<"-1";
}