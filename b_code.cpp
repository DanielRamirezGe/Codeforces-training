#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a; 
	cin>>n;
	vector<int> vec;
	for(int i=0; i<n; i++)
	{
		cin>>a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	for(int i=0; i<n; i++)
	{
		if(i!= n-1)
			cout<<vec[i]<<" ";
		else
			cout<<vec[i]<<endl;
	}
	
}