#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases,a,b,c,n;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		vector<int> vec;
		cin>>a>>b>>c>>n;
		vec.push_back(a);
		vec.push_back(b);
		vec.push_back(c);
		sort(vec.begin(), vec.end());
		int menos=vec[2]-vec[0]+vec[2]-vec[1];
		int otro=n-menos;
		if(otro>=0 and otro%3==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;


	}
}