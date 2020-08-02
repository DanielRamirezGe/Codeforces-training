#include <bits/stdc++.h>
using namespace std;
int main()
{
	string cad;
	cin>>cad;
	vector<int> vec;
	for(int i=0; i<cad.size(); i++)
		if(i%2==0)
			vec.push_back(cad[i]-'0');

	sort(vec.begin(), vec.end());
	for(int i=0; i<vec.size(); i++)
	{
		cout<<vec[i];
		if( i!=vec.size()-1)
			cout<<'+';
	}
	cout<<endl;
}