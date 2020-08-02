#include <bits/stdc++.h>
using namespace std;
int main()
{
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++)
	{
		vector <int> vec;
		int a,b,c;
		cin>>a>>b>>c;
		vec.push_back(a);
		vec.push_back(b);
		vec.push_back(c);
		sort(vec.begin(), vec.end());
		if(vec[0]+ vec[1]>=vec[2]-1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
}